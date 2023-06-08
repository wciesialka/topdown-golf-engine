/**
 * @file Window.cpp
 * @brief This file contains definitions for the Window class.
 * 
 * @author Willow Ciesialka
 * @date 2023-06-07
*/

#include "Window.hpp"
#include "../Geometry/Vector2.hpp"

using GolfEngine::Window;

void Window::handleEvent(sf::Event event){
    if (event.type == sf::Event::Closed)
    {
        this->render_window->close();
    }
}

void Window::beginDisplay(){
    while (this->render_window->isOpen())
    {
        sf::Event event;
        while (render_window->pollEvent(event))
        {
            this->handleEvent(event);

            this->render_window->clear(this->bgcolor);

            GolfEngine::RenderableVisitor visitor(this->render_window, 
                                                  this->getFocusPoint(), 
                                                  this->getFocusPoint() + GolfEngine::Vector2(SCREEN_W, SCREEN_H));
            this->scene->render(visitor);

            this->render_window->display();
        }
    }
}