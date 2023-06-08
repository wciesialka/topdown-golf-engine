/**
 * @file Polygon.cpp
 * @brief This file contains definitions for the Polygon shape class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-07
*/

#include "Polygon.hpp"
#include <cstring>

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
    this->vertices[this->getVertexCount()] = point;
    this->setVertexCount(this->getVertexCount() + 1);
}