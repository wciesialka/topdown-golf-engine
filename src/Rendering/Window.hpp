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

#include <SFML/Graphics.hpp>
#include "../GameManagement/Scene.hpp"
#include "../Vector2.hpp"
#include "../Rendering/RenderableVisitor.hpp"

namespace GolfEngine
{
    class Window
    {
    public:
        Window(GolfEngine::Scene *scene) : scene(scene),
                                           focus(GolfEngine::Vector2::zero),
                                           bgcolor(sf::Color::Black)
        {
            this->render_window = new sf::RenderWindow(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
        }

        Window(GolfEngine::Scene *scene, int background_color) : scene(scene),
                                           focus(GolfEngine::Vector2::zero),
                                           bgcolor(sf::Color(background_color))
        {
            this->render_window = new sf::RenderWindow(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
        }

        ~Window()
        {
            delete this->render_window;
        }

        /**
         * @brief Open the window and display the game.
         */
        void beginDisplay();

        /**
         * @brief Handle a window event.
         *
         * @param event Event to handle.
         */
        void handleEvent(sf::Event event);

        /**
         * @brief Set the focus point.
         *
         * The focus point is defined as the top-left-most point that is
         * visible on the screen.
         *
         * @param vec The new focus point.
         */
        inline void setFocusPoint(GolfEngine::Vector2 vec)
        {
            this->focus = vec;
        }

        /**
         * @brief Get the focus point.
         *
         * The focus point is defined as the top-left-most point that is
         * visible on the screen.
         *
         * @returns The focus point.
         */
        inline GolfEngine::Vector2 getFocusPoint() const
        {
            return this->focus;
        }

    private:
        sf::RenderWindow *render_window;
        GolfEngine::Scene *scene;
        GolfEngine::Vector2 focus;

        sf::Color bgcolor;
    };
}

#endif