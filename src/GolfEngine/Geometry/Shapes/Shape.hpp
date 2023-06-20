/**
 * @file Shape.hpp
 * @brief This file contains declerations for the Shape abstract class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-08
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "../../Rendering/Renderable.hpp"
#include "../../Rendering/RenderableVisitor.hpp"
#include "../Vector2.hpp"
#include "../Line.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>

namespace GolfEngine
{
    class Shape : public Renderable
    {
    public:
        Shape() : GolfEngine::Renderable() { this->setColor(0); };
        Shape(GolfEngine::Vector2 pos) : GolfEngine::Renderable(pos) { this->setColor(0); };
        Shape(GolfEngine::Vector2 pos, float rotation) : GolfEngine::Renderable(pos, rotation) { this->setColor(0); };

        virtual ~Shape() {}

        /**
         * @brief Returns whether the shape contains a point.
         *
         * @param point The point to check.
         * @returns True if the point is encompassed by the shape, false otherwise.
         * @note This assumes the point is in LOCAL space. To check if a world point is inside
         * the shape, make use of the inherited \ref GolfEngine::Renderable::worldToLocal(GolfEngine::Vector2)
         * function.
         */
        virtual bool contains(const GolfEngine::Vector2& point) const = 0;

        /**
         * @brief Compare if the shape intersects a line.
         *
         * @param line Line to compare against.
         * @returns True if there is an intersection, false otherwise.
         */
        virtual bool intersects(const GolfEngine::Line& line) const = 0;

        /**
         * @brief Returns the perimeter of the shape.
         *
         * @returns Perimeter of the shape
         */
        virtual float getPerimeter() const = 0;

        /**
         * @brief Returns the area of the shape.
         *
         * @returns Area of the shape.
         */
        virtual float getArea() const = 0;

        /**
         * @brief Get the "centroid" of the shape.
         *
         * @returns The centroid of the shape.
         */
        virtual GolfEngine::Vector2 getCentroid() const = 0;

        /**
         * @brief Set the color of the shape.
         *
         * @param rgb Color as integer 0xRRGGBB.
         */
        inline void setColor(int rgb)
        {
            if (rgb < 0 || rgb > 0xFFFFFF)
            {
                throw std::out_of_range("Color must be int containing three bytes (R, G, B) in form 0xRRGGBB.");
            }
            this->color = sf::Color((rgb << 8) | 0xFF);
        }

        inline sf::Color getColor() const
        {
            return this->color;
        }

        inline void visit(GolfEngine::RenderableVisitor* visitor){
            this->render(visitor->getWindow());
        }

    private:
        sf::Color color;
    };
}

#endif