/**
 * @file Window.hpp
 * @brief This file contains declerations for the Window class
 *
 * The Window class is a wrapper for the SFML Window.
 *
 * @author Willow Ciesialka
 * @date 2023-06-06
 */

#ifndef WINDOW_H
#define WINDOW_H

#define SCREEN_W 800
#define SCREEN_H 600
#define WINDOW_TITLE "Golf Game"

#include <SFML/Window.hpp>
#include "Scene.hpp"
#include "Vector2.hpp"

namespace GolfEngine
{
    class Window
    {
    public:
        Window(GolfEngine::Scene *scene) : scene(scene),
                                           focus(GolfEngine::Vector2::zero)
        {
            this->window = new sf::Window(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
        }

        ~Window()
        {
            delete this->window;
        }

        /**
         * @brief Open the window and display the game.
         */
        void beginDisplay()
        {
            while (this->window->isOpen())
            {
                sf::Event event;
                while (window->pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window->close();
                    }
                    else
                    {
                        this->handleEvent(event);
                    }

                    this->renderRenderables();
                }
            }
        }

        /**
         * @brief Handle a window event.
         *
         * @param event Event to handle.
         */
        void handleEvent(sf::Event event);

    private:
        sf::Window *window;
        GolfEngine::Scene *scene;
        GolfEngine::Vector2 focus;
    }
}

#endif