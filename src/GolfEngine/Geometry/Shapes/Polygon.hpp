/**
 * @file Polygon.hpp
 * @brief This file contains declerations for the Polygon shape class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.hpp"
#include "Circle.hpp"
#include "../Vector2.hpp"
#include "../Line.hpp"
#include <stdexcept>
#include <SFML/Graphics.hpp>

namespace GolfEngine
{

    class Polygon : public Shape
    {
    public:
        /**
         * @brief A polygon cannot have less than three sides.
        */
        static const unsigned int MIN_POSSIBLE_VERTICES = 3;

        Polygon() : GolfEngine::Shape()
        {
            this->setMaxVertices(Polygon::MIN_POSSIBLE_VERTICES);
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
            this->setVertexCount(0);
            this->setVertexCount(0);
        }

        Polygon(uint max_vertices) : GolfEngine::Shape()
        Polygon(uint max_vertices) : GolfEngine::Shape()
        {
            this->setMaxVertices(max_vertices);
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
            this->setVertexCount(0);
            this->setVertexCount(0);
        }

        Polygon(GolfEngine::Vector2 pos) : GolfEngine::Shape(pos)
        Polygon(GolfEngine::Vector2 pos) : GolfEngine::Shape(pos)
        {
            this->setMaxVertices(Polygon::MIN_POSSIBLE_VERTICES);
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
            this->setVertexCount(0);
            this->setVertexCount(0);
        }

        Polygon(GolfEngine::Vector2 pos, uint max_vertices) : GolfEngine::Shape(pos)
        Polygon(GolfEngine::Vector2 pos, uint max_vertices) : GolfEngine::Shape(pos)
        {
            this->setMaxVertices(max_vertices);
            this->vertices = new GolfEngine::Vector2[this->getMaxVertices()];
            this->setVertexCount(0);
            this->setVertexCount(0);
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
         * @note Points must be added either CLOCKWISE or COUNTER-CLOCKWISE.
         */
        void addPoint(GolfEngine::Vector2 point);

        /**
         * @brief Sets the vertex on the polygon to the specified vector.
         *
         * @param i Index of the vertex.
         * @param point New point.
         * @throws std::length_error If trying to set a point beyond the current amount of vertices.
         */
        inline void setPoint(uint i, GolfEngine::Vector2 point)
        {
            if (i > this->getVertexCount())
            {
                throw std::length_error("Cannot set a point outside of current polygon vertex count.");
            }
            this->vertices[i] = point;
        }

        /**
         * @brief Gets the vertex on the polygon.
         *
         * @param i Index of the vertex.
         * @returns Vertex on polygon.
         */
        inline GolfEngine::Vector2 getPoint(uint i) const
        {
            if (i > this->getVertexCount())
            {
                throw std::out_of_range("Cannot get a point outside of current polygon vertex count.");
            }
            return this->vertices[i];
        }

        /**
         * @brief Check whether the polygon is interesecting a line.
         *
         * @param line Line to compare against.
         * @returns True if there is an intersection, false otherwise.
         */
        virtual bool intersects(const GolfEngine::Line *line) const;

        /**
         * @brief Check if the polygon is intersecting another polygon.
         *
         * @param other Polygon to compare against.
         * @returns True if there is an intersection, false otherwise.
         */
        bool intersects(const GolfEngine::Polygon *other) const;

        /**
         * @brief Check if the polygon is intersecting a circle.
         *
         * @param circle Circle to compare against.
         * @returns True if there is an intersection, false otherwise.
         */
        bool intersects(const GolfEngine::Circle *circle) const;

        /**
         * @brief Compare if the circle is intersecting a polygon.
         *
         * @param circle Circle to compare with.
         * @param polygon Polygon to compare against.
         * @returns True if there is an intersection, false otherwise.
         */
        inline friend bool intersects(const GolfEngine::Circle *circle, const GolfEngine::Polygon *polygon)
        {
            return polygon->intersects(circle);
        }

        virtual float getPerimeter() const;
        virtual float getArea() const;
        virtual GolfEngine::Vector2 getCentroid() const;
        virtual bool contains(Vector2 point) const;
        virtual void render(sf::RenderWindow *window);

        bool operator==(const Polygon &other) const;
        inline bool operator!=(const Polygon &other) const { return !(*this == other); }

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
            if (new_max < Polygon::MIN_POSSIBLE_VERTICES)
            {
                throw std::out_of_range("A polygon cannot have less than three sides.");
            }
            if (new_max < this->getMaxVertices()){
                throw std::domain_error("Cannot set the max number of vertices to be less than what it was.");
            }
            this->max_vertices = new_max;
        };

        /**
         * @brief Set the current number of vertices on the polygon.
         *
         * @param new_count New amount of vertices.
         * @throws std::length_error If the new count exceeds the maximum vertices, an error is thrown.
         */
        inline void setVertexCount(uint new_count)
        {
            if (new_count > this->getMaxVertices())
            {
                throw std::length_error("Vertex count cannot exceed max vertices.");
            }
            this->vertex_count = new_count;
        }
    };
}

#endif