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

using GolfEngine::Window;
using namespace std::chrono;

void Window::beginDisplay()
{
    if (this->getActiveLevel() == nullptr)
    {
        throw std::runtime_error("Cannot render window with uninitialized level.");
    }
    GolfEngine::Vector2 screen_size(this->getWidth(), this->getHeight());
    GolfEngine::RenderableVisitor visitor(this->getDisplay(), screen_size);

    long unsigned int last_update = duration_cast<milliseconds>(
                            system_clock::now().time_since_epoch())
                            .count();

    std::cout << last_update << std::endl;

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
        long unsigned int now = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch())
                        .count();

        float time_diff = (float)(now - last_update);

        this->active_level->frameUpdate(time_diff);

        this->active_level->visit(&visitor);

        this->render_window->display();

        last_update = now;
    }
}