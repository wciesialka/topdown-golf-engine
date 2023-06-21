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

using GolfEngine::Window;
using namespace std::chrono;

void Window::beginDisplay()
{
    GolfEngine::Vector2 screen_size(this->getWidth(), this->getHeight());
    GolfEngine::RenderableVisitor visitor(this->getDisplay(), screen_size);

    float last_update = duration_cast<milliseconds>(
                            system_clock::now().time_since_epoch())
                            .count() /
                        1000;

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
            if (event.type == sf::Event::KeyPressed)
            {
                this->getActiveLevel()->onKeyDown(event.key.code);
                continue;
            }
            if (event.type == sf::Event::KeyReleased)
            {
                this->getActiveLevel()->onKeyUp(event.key.code);
                continue;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                this->getActiveLevel()->onMouseDown(event.mouseButton);
                continue;
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                this->getActiveLevel()->onMouseUp(event.mouseButton);
                continue;
            }
            if (event.type == sf::Event::MouseMoved)
            {
                GolfEngine::Vector2 mousePos(event.mouseMove.x, event.mouseMove.y);
                this->getActiveLevel()->setMousePos(mousePos);
                this->getActiveLevel()->onMouseMove(event.mouseMove);
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
        }
        this->render_window->clear(this->bgcolor);

        // My formatter turned this into poetry.
        float now = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch())
                        .count() /
                    1000;

        this->active_level->frameUpdate(now - last_update);
        last_update = now;

        this->active_level->visit(&visitor);

        this->render_window->display();
    }
}