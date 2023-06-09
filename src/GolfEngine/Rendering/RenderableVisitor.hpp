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
#include "Window.hpp"
#include "../Geometry/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class RenderableVisitor
    {
    public:
        RenderableVisitor(GolfEngine::Window *window) : window(window) {};

        inline GolfEngine::Window* getWindow() const {
            return this->window;
        }

    private:
        GolfEngine::Window *window;
    };
}

#endif