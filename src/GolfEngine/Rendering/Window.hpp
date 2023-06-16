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
#include "../GameManagement/Levels/Level.hpp"
#include "../Geometry/Vector2.hpp"
#include "RenderableVisitor.hpp"

namespace GolfEngine
{
    class Window
    {
    public:
        Window() : focus(GolfEngine::Vector2::zero),
                   bgcolor(sf::Color::Black)
        {
            this->render_window = new sf::RenderWindow(sf::VideoMode(SCREEN_W, SCREEN_H), WINDOW_TITLE);
        }

        Window(int background_color) : focus(GolfEngine::Vector2::zero),
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

        inline int getWidth() const
        {
            return SCREEN_W;
        }

        inline int getHeight() const
        {
            return SCREEN_H;
        }

        /**
         * @brief Returns the render window of the window.
         *
         * @returns Pointer to the render window.
         */
        inline sf::RenderWindow *getDisplay() const
        {
            return this->render_window;
        }

        /**
         * @brief Check whether a point is constrained by the screen.
         *
         * @param point Point to check.
         * @returns True if the point is within screen bounds, false otherwise.
         */
        inline bool contains(GolfEngine::Vector2 point) const
        {
            return (point.x >= this->getFocusPoint().x && point.y >= this->getFocusPoint().y) && (point.x <= (this->getFocusPoint().x + this->getWidth()) && point.y <= (this->getFocusPoint().y + this->getHeight()));
        }

        /**
         * @brief Load a level.
         * 
         * @param level Level to load.
        */
        inline void loadLevel(GolfEngine::Level* level){
            this->active_level = level;
            this->active_level->initialize();
        }

    private:
        sf::RenderWindow *render_window;
        GolfEngine::Level *active_level;
        GolfEngine::Vector2 focus;

        sf::Color bgcolor;
    };
}

#undef SCREEN_W
#undef SCREEN_H
#endif