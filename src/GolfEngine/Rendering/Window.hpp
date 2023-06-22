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
        Window(unsigned int width, unsigned int height) : width(width), height(height),
                                                          active_level(nullptr),
                                                          focus(GolfEngine::Vector2::zero),
                                                          bgcolor(sf::Color::Black)
        {
            this->render_window = new sf::RenderWindow(sf::VideoMode(width, height), WINDOW_TITLE, Window::WINDOW_FLAGS);
        }

        Window(unsigned int width, unsigned int height, int background_color) : width(width), height(height),
                                                                                active_level(nullptr),
                                                                                focus(GolfEngine::Vector2::zero),
                                                                                bgcolor(sf::Color(background_color))
        {
            this->render_window = new sf::RenderWindow(sf::VideoMode(width, height), WINDOW_TITLE, Window::WINDOW_FLAGS);
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

        /**
         * @brief Returns the width of the window.
         *
         * @returns The width of the window in pixels.
         */
        inline unsigned int getWidth() const
        {
            return this->width;
        }

        /**
         * @brief Returns the height of the window.
         *
         * @returns The height of the window in pixels.
         */
        inline unsigned int getHeight() const
        {
            return this->height;
        }

        inline GolfEngine::Vector2 getSize() const
        {
            return GolfEngine::Vector2((float)(this->getWidth()), (float)(this->getHeight()));
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
        inline void loadLevel(GolfEngine::Level *level)
        {
            this->active_level = level;
            this->active_level->initialize();
        }

        /**
         * @brief Close the window and handle any cleanup.
         */
        inline void close()
        {
            this->render_window->close();
        }

        /**
         * @brief Get a pointer to the active level.
         *
         * @return Pointer to the window's currently active level.
         */
        inline GolfEngine::Level *getActiveLevel()
        {
            return this->active_level;
        }

    private:
        static const sf::Uint32 WINDOW_FLAGS = sf::Style::Titlebar | sf::Style::Close;

        unsigned int width;
        unsigned int height;

        sf::RenderWindow *render_window;
        GolfEngine::Level *active_level;
        GolfEngine::Vector2 focus;

        sf::Color bgcolor;
    };
}

#undef SCREEN_W
#undef SCREEN_H
#endif