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
#include "../Vector2.hpp"
#include <stdexcept>

namespace GolfEngine
{
    class Shape : public Renderable
    {
    public:
        /**
         * @brief Returns whether the shape is interesecting another shape.
         *
         * @param other The other shape to check.
         * @returns True if the shapes are intersecting, false otherwise.
         */
        virtual bool intersects(Shape *other) = 0;

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
        virtual GolfEngine::Vector2 getCentroid();

        /**
         * @brief Set the color of the shape.
         * 
         * @param rgb Color as integer 0xRRGGBB.
        */
        inline void setColor(int rgb){
            if(rgb < 0 || rgb > 0xFFFFFF){
                throw std::out_of_range("Color must be int containing three bytes (R, G, B) in form 0xRRGGBB.");
            }
            this->color = (rgb << 8) | 0xFF; 
        }

        inline int getColor() const {
            return this->color;
        }

    private:
        int color;
    };
}

#endif