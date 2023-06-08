/**
 * @file Polygon.hpp
 * @brief This file contains declerations for the Polygon shape class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "../../Rendering/Renderable.hpp"
#include "../Vector2.hpp"
#include <stdexcept>

namespace GolfEngine
{

    class Polygon : public Renderable
    {
    public:
        Polygon() : max_vertices(3),
                    vertex_count(0)
        {
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
        }

        Polygon(uint max_vertices) : vertex_count(0)
        {
            this->setMaxVertices(max_vertices);
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
        }

        /**
         * @brief Get the current max vertices of the polygon.
         *
         * @returns Max vertices of the polygon.
         */
        inline uint getMaxVertices() const
        {
            return this->max_vertices;
        }

        /**
         * @brief Get the current vertex count.
         *
         * @returns The current amount of vertices on the polygon.
         */
        inline uint getVertexCount() const
        {
            return this->vertex_count;
        }

        /**
         * @brief Add a point to the polygon.
         * 
         * @param point The point to add to the polygon.
        */
        void addPoint(GolfEngine::Vector2 point);

    private:
        uint max_vertices;
        uint vertex_count;

        GolfEngine::Vector2 *vertices;

        /**
         * @brief Set the max vertices of the polygon.
         *
         * @param new_max New amount of max vertices.
         * @throws std::out_of_range If the value is less than 3, an exception will be thrown.
         */
        inline void setMaxVertices(uint new_max)
        {
            if (new_max < 3)
            {
                throw std::out_of_range("A polygon cannot have less than three sides.");
            }
            this->max_vertices = new_max;
        };

        /**
         * @brief Set the current number of vertices on the polygon.
         * 
         * @param new_count New amount of vertices.
         * @throws std::length_error If the new count exceeds the maximum vertices, an error is thrown.
        */
        inline void setVertexCount(uint new_count){
            if (new_count > this->getMaxVertices()){
                throw std::length_error("Vertex count cannot exceed max vertices.");
            }
            this->vertex_count = new_count;
        }
    };
}

#endif