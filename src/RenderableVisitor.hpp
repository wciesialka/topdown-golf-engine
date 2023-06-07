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
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class RenderableVisitor
    {
    public:
        RenderableVisitor(sf::RenderWindow *window) : window(window){};

        /**
         * @brief "Visit" a Renderable, and render it on the screen.
         *
         * @param object Renderable object to render.
         */
        inline void visit(GolfEngine::Renderable *object)
        {
            object->render(this->window);
        };

    private:
        sf::RenderWindow *window;
    };
}

#endif