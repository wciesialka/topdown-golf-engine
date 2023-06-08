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
        RenderableVisitor(sf::RenderWindow *window, 
                          GolfEngine::Vector2 top_left,
                          GolfEngine::Vector2 bottom_right) : window(window),
                                                              top_left(top_left),
                                                              bottom_right(bottom_right) {};

        /**
         * @brief "Visit" a Renderable, and render it on the screen.
         * 
         * An object will only be rendered if it is within the bounds of the screen.
         *
         * @param object Renderable object to render.
         */
        inline void visit(GolfEngine::Renderable *object)
        {
            GolfEngine::Vector2 pos = object->getPosition();
            if(pos.x >= top_left.x && pos.x <= bottom_right.x && pos.y >= top_left.y && pos.y <= bottom_right.y ){
                object->render(this->window);
            }
        };

    private:
        sf::RenderWindow *window;

        GolfEngine::Vector2 top_left;
        GolfEngine::Vector2 bottom_right;
    };
}

#endif