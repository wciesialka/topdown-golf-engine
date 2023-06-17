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
            switch(event.type){
                case sf::Event::Closed:
                    this->close();
                    break;
                case sf::Event::KeyPressed:
                    this->getActiveLevel()->onKeyDown(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    this->getActiveLevel()->onKeyUp(event.key.code);
                    break;
                case sf::Event::MouseButtonPressed:
                    this->getActiveLevel()->onMouseDown(event.mouseButton);
                    break;
                case sf::Event::MouseButtonReleased:
                    this->getActiveLevel()->onMouseUp(event.mouseButton);
                    break;
                case sf::Event::MouseMoved:
                    GolfEngine::Vector2 mousePos(event.mouseMove.x, event.mouseMove.y);
                    this->getActiveLevel()->setMousePos(mousePos);
                    this->getActiveLevel()->onMouseMove(event.mouseMove);
                    break;
                case sf::Event::LostFocus:
                    this->getActiveLevel()->pause();
                    break;
                case sf::Event::GainedFocus:
                    this->getActiveLevel()->resume();
                    break;
                default:
                    break;
            }
        }
        this->render_window->clear(this->bgcolor);

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