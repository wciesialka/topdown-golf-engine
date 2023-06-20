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
#include "../Line.hpp"
#include <cstring>
#include <stdexcept>

#include <iostream>

using GolfEngine::Polygon;

void Polygon::addPoint(GolfEngine::Vector2 point)
{
    // If we have hit our max vertices, we need to adjust our list of vertices.
    if (this->getVertexCount() == this->getMaxVertices())
    {
        this->setMaxVertices(this->getMaxVertices() + 1);
        GolfEngine::Vector2 *new_vertices = new GolfEngine::Vector2[this->getMaxVertices()];
        memcpy(new_vertices, this->vertices, this->getVertexCount());
        delete[] this->vertices;
        this->vertices = new_vertices;
    }
    this->setPoint(this->getVertexCount(), point);
    this->setVertexCount(this->getVertexCount() + 1);
}

float Polygon::getPerimeter() const
{
    if (this->getVertexCount() < 3)
    {
        throw std::logic_error("Cannot get the perimeter of an open polygon.");
    }
    Vector2 a, b;
    float perimeter = 0;
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        a = this->getPoint(i);
        b = this->getPoint((i + 1) % this->getVertexCount());
        perimeter += a.distance(b);
    }
    return perimeter;
}

float Polygon::getArea() const
{
    if (this->getVertexCount() < 3)
    {
        throw std::logic_error("Cannot get the area of an open polygon.");
    }
    // A polygon encompasses the area 1/2 * summation(x_i * y_i+1 - x_i+1 * y_i) for each point in the Polygon.
    Vector2 a, b;
    float summation = 0;
    uint j = this->getVertexCount() - 1;
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        a = this->getPoint(i);
        b = this->getPoint(j);
        float iteration = (a.x + b.x) * (a.y - b.y);
        summation += iteration;
        j = i;
    }
    return summation / 2.0;
}

GolfEngine::Vector2 Polygon::getCentroid() const
{
    // See Paul Bourke's Centroid paper for more info.
    // http://paulbourke.net/geometry/polygonmesh/centroid.pdf

    float area = this->getArea();
    float x_summation = 0, y_summation = 0;
    float scalar = 1 / (6 * area);

    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        uint j = (i + 1) % this->getVertexCount();
        GolfEngine::Vector2 a = this->getPoint(i);
        GolfEngine::Vector2 b = this->getPoint(j);
        float factor = (a.x * b.y) - (b.x * a.y);
        x_summation += (a.x + b.x) * factor;
        y_summation += (a.y + b.y) * factor;
    }

    return scalar * GolfEngine::Vector2(x_summation, y_summation);
}

void Polygon::render(sf::RenderWindow *window)
{
    if (this->getVertexCount() < Polygon::MIN_POSSIBLE_VERTICES)
    {
        throw std::runtime_error("Cannot render a polygon with less than three sides.");
    }

    sf::ConvexShape convex;
    convex.setPointCount(this->getVertexCount());

    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        Vector2 render_pos = this->localToWorld(this->getPoint(i));
        convex.setPoint(i, sf::Vector2f(render_pos.x, render_pos.y));
    }

    convex.setFillColor(sf::Color(this->getColor()));

    window->draw(convex);
}

bool Polygon::contains(const GolfEngine::Vector2& point) const
{
    bool collision = false;

    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        uint j = (i + 1) % this->getVertexCount();
        GolfEngine::Vector2 a = this->localToWorld(this->getPoint(i));
        GolfEngine::Vector2 b = this->localToWorld(this->getPoint(j));

        // Check if the point is between the two points in the y axis.
        if ((a.y > point.y) != (b.y > point.y))
        {
            // Use the Jordan Curve Theorem
            float winding_number = (b.x - a.x) * (point.y - a.y) / (b.y - a.y) + a.x;
            if (point.x < winding_number)
            {
                collision = !collision;
            }
        }
    }

    return collision;
}

bool Polygon::intersects(const GolfEngine::Line& line) const
{
    // Check if the given line intersects any of the
    // lines formed by each consecutive vertex on the polygon.
    uint j = this->getVertexCount() - 1;
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        GolfEngine::Vector2 a = this->localToWorld(this->getPoint(i));
        GolfEngine::Vector2 b = this->localToWorld(this->getPoint(j));

        GolfEngine::Line edge(a, b);
        if (edge.intersects(line))
        {
            return true;
        }

        j = i;
    }
    return false;
}

bool Polygon::intersects(const Polygon& other) const
{
    if (*this == other)
    {
        return true;
    }
    // Check to see if the given polygon intersects
    // any of the lines formed by each consecutive vertex
    // on the polygon.
    uint j = this->getVertexCount() - 1;
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        GolfEngine::Vector2 a = this->getPoint(i);
        GolfEngine::Vector2 b = this->getPoint(j);

        GolfEngine::Line edge(a, b);
        if (other.intersects(edge))
        {
            return true;
        }

        j = i;
    }
    return false;
}

bool Polygon::operator==(const Polygon &other) const
{
    // First, check that they are of the same cardinality.
    if (!(this->getMaxVertices() == other.getMaxVertices() && this->getVertexCount() == other.getVertexCount()))
    {
        return false;
    }
    // Then, check to make sure each vertex is the same.
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        if (this->getPoint(i) != other.getPoint(i))
        {
            return false;
        }
    }
    return true;
}

bool Polygon::intersects(const GolfEngine::Circle& circle) const
{
    // Check if any of the lines formed by consecutive vertices intersect the circle.
    uint j = this->getVertexCount() - 1;
    for (uint i = 0; i < this->getVertexCount(); i++)
    {
        GolfEngine::Vector2 a = this->localToWorld(this->getPoint(i));
        GolfEngine::Vector2 b = this->localToWorld(this->getPoint(j));

        GolfEngine::Line edge(a, b);
        if (circle.intersects(edge))
        {
            return true;
        }

        j = i;
    }
    return false;
}