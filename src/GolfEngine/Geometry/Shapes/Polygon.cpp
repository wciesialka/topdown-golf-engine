/**
 * @file Polygon.cpp
 * @brief This file contains definitions for the Polygon shape class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-07
*/

#include "Polygon.hpp"
#include "Shape.hpp"
#include "../Vector2.hpp"
#include <cstring>
#include <stdexcept>

using GolfEngine::Polygon;

void Polygon::addPoint(GolfEngine::Vector2 point){
    // If we have hit our max vertices, we need to adjust our list of vertices.
    if(this->getVertexCount() == this->getMaxVertices()){
        this->setMaxVertices(this->getMaxVertices() + 1);
        GolfEngine::Vector2* new_vertices = new GolfEngine::Vector2[this->getMaxVertices()];
        memcpy(new_vertices, this->vertices, this->getVertexCount());
        delete[] this->vertices;
        this->vertices = new_vertices;
    }
    this->setPoint(this->getVertexCount(), point);
    this->setVertexCount(this->getVertexCount() + 1);
}

float Polygon::getPerimeter() const{
    if(this->getVertexCount() < 3){
        throw std::logic_error("Cannot get the perimeter of an open polygon.");
    }
    Vector2 a, b;
    float perimeter = 0;
    for(uint i = 0; i < this->getVertexCount(); i++){
        a = this->getPoint(i);
        b = this->getPoint((i+1) % this->getVertexCount());
        perimeter += a.distance(b);
    }
    return perimeter;
}

float Polygon::getArea() const{
    if(this->getVertexCount() < 3){
        throw std::logic_error("Cannot get the area of an open polygon.");
    }
    // A polygon encompasses the area 1/2 * summation(x_i * y_i+1 - x_i+1 * y_i) for each point in the Polygon.
    Vector2 a, b;
    float area = 0;
    float summation;
    for(uint i = 0; i < this->getVertexCount(); i++){
        uint j = (i + 1) % this->getVertexCount();
        a = this->getPoint(i);
        b = this->getPoint(j);
        summation += (a.x * b.y) - (b.x * a.y);
    }
    return (summation / 2);
}

GolfEngine::Vector2 Polygon::getCentroid() const{
    // See Paul Bourke's Centroid paper for more info.
    // http://paulbourke.net/geometry/polygonmesh/centroid.pdf

    float area = this->getArea();
    float x_summation = 0, y_summation = 0;
    float scalar = 1/(6*area);

    for(uint i = 0; i < this->getVertexCount(); i++){
        uint j = (i + 1) % this->getVertexCount();
        GolfEngine::Vector2 a = this->getPoint(i);
        GolfEngine::Vector2 b = this->getPoint(j);
        float factor = (a.x * b.y) - (b.x * a.y);
        x_summation += (a.x + b.x) * factor;
        y_summation += (a.y + b.y) * factor;
    }

    return scalar * GolfEngine::Vector2(x_summation, y_summation);
}

void Polygon::render(sf::RenderWindow* window, GolfEngine::Vector2 offset){
    if(this->getVertexCount() < 3){
        throw std::logic_error("Cannot render an open polygon.");
    }

    sf::ConvexShape convex;
    convex.setPointCount(this->getVertexCount());

    for(uint i = 0; i < this->getVertexCount(); i++){
        Vector2 render_pos = offset + this->getPoint(i);
        convex.setPoint(i, sf::Vector2f(render_pos.x, render_pos.y));
    }

    convex.setFillColor(sf::Color(this->getColor()));

    window->draw(convex);
}

bool Polygon::contains(GolfEngine::Vector2 point) const{
    bool collision = false;

    for(uint i = 0; i < this->getVertexCount(); i++){
        uint j = (i + 1) % this->getVertexCount();
        GolfEngine::Vector2 a = this->getPoint(i);
        GolfEngine::Vector2 b = this->getPoint(j);

        // Check if the point is between the two points in the y axis.
        if( (a.y > point.y) != (b.y > point.y) ){
            // Use the Jordan Curve Theorem
            float winding_number = (b.x - a.x) * (point.y - a.y) / (b.y - a.y) + a.x;
            if( point.x < winding_number ){
                collision = !collision;
            }
        }
    }

    return collision;
}