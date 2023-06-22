/**
 * @file Window.cpp
 * @brief This file contains definitions for the Window class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#include "Window.hpp"
#include "../Geometry/Vector2.hpp"
#include <chrono>
#include <stdexcept>
#include <iostream>
#include<unistd.h>

using GolfEngine::Window;
using namespace std::chrono;

unsigned long long getTimestamp()
{
    return duration_cast<milliseconds>(
               system_clock::now().time_since_epoch())
        .count();
}

void Window::beginDisplay()
{
    if (this->getActiveLevel() == nullptr)
    {
        throw std::runtime_error("Cannot render window with uninitialized level.");
    }
    GolfEngine::Vector2 screen_size(this->getWidth(), this->getHeight());
    GolfEngine::RenderableVisitor visitor(this->getDisplay(), screen_size);

    unsigned long long now;
    unsigned long long last_update = getTimestamp();

    while (this->render_window->isOpen())
    {
        sf::Event event;
        while (this->render_window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                this->close();
                continue;
            }
            if (event.type == sf::Event::LostFocus)
            {
                this->getActiveLevel()->pause();
                continue;
            }
            if (event.type == sf::Event::GainedFocus)
            {
                this->getActiveLevel()->resume();
                continue;
            }
            GolfEngine::Vector2 mousePos;
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mousePos = GolfEngine::Vector2(event.mouseButton.x, event.mouseButton.y);
                this->getActiveLevel()->onMouseDown(event.mouseButton);
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                mousePos = GolfEngine::Vector2(event.mouseButton.x, event.mouseButton.y);
                this->getActiveLevel()->onMouseUp(event.mouseButton);
            }
            if (event.type == sf::Event::MouseMoved)
            {
                mousePos = GolfEngine::Vector2(event.mouseMove.x, event.mouseMove.y);
                this->getActiveLevel()->onMouseMove(event.mouseMove);
            }
            this->getActiveLevel()->setMousePos(mousePos);
        }
        this->render_window->clear(this->bgcolor);

        // My formatter turned this into poetry.
        now = getTimestamp();

        unsigned long long time_diff = now - last_update;
        std::cout << "Last update was " << time_diff << "ms ago..." << std::endl;

        this->active_level->frameUpdate(time_diff);

        last_update = now;

        this->active_level->visit(&visitor);

        this->render_window->display();
        usleep(33333);
    }
}