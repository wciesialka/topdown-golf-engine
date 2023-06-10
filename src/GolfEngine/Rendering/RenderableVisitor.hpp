/**
 * @file RenderableVisitor.hpp
 * @brief This file contains declerations for the RenderableVisitor class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef RENDERABLE_VISITOR_H
#define RENDERABLE_VISITOR_H

#include "Renderable.hpp"
#include "../Geometry/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class RenderableVisitor
    {
    public:
        RenderableVisitor(sf::RenderWindow *window, GolfEngine::Vector2 focus_size) : window(window), focus(GolfEngine::Vector2::zero), focus_size(focus_size) {};

        inline sf::RenderWindow* getWindow() const {
            return this->window;
        }

        /**
         * @brief Determine whether the visitor can view a point
         * 
         * @returns True if the point is within screen bounds, false otherwise.
        */
        inline bool canView(GolfEngine::Vector2 point){
            GolfEngine::Vector2 focus_max = this->focus + this->focus_size;
            return (this->focus.x <= point.x && this->focus.y <= point.y && point.x <= focus_max.x && point.y <= focus_max.y);
        }

    private:
        sf::RenderWindow *window;
        GolfEngine::Vector2 focus;
        GolfEngine::Vector2 focus_size;
    };
}

#endif