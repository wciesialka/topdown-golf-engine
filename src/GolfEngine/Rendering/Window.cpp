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
    GolfEngine::RenderableVisitor visitor(this);
    while (this->render_window->isOpen())
    {
        sf::Event event;
        while (render_window->pollEvent(event))
        {
            this->handleEvent(event);

            this->render_window->clear(this->bgcolor);

            this->scene->visit(&visitor);

            this->render_window->display();
        }
    }
}