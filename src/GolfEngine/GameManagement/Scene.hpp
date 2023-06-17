/**
 * @file Scene.hpp
 * @brief This file contains declerations for the Scene class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-02
 */

#ifndef SCENE_H
#define SCENE_H

#include "../Geometry/Vector2.hpp"
#include "../Rendering/RenderableVisitor.hpp"
#include "Entities/Entity.hpp"
#include "Tile.hpp"
#include "Tilemap.hpp"
#include "Collision.hpp"
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class Scene
    {
    public:
        Scene()
        {
            this->tilemap = new GolfEngine::Tilemap();
        }
        Scene(unsigned int side_length)
        {
            this->tilemap = new GolfEngine::Tilemap(side_length);
        };
        ~Scene()
        {
            delete this->tilemap;
        }

        /**
         * @brief This function adds an entity to the scene.
         *
         * @param ent The entity to add to the scene.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addEntity(Entity *ent);

        /**
         * @brief This function adds a tile to the scene.
         *
         * @param tile The tile to add to the scene.
         * @returns True if the addition was a success, false otherwise.
         */
        inline bool addTile(Tile *tile)
        {
            return this->tilemap->addTile(tile);
        };

        /**
         * @brief Handle event
         */
        virtual void handleEvent(sf::Event event) = 0;

        /**
         * @brief Frame update
         *
         * @param dt Time since last frame update (in ms)
         */
        virtual void frameUpdate(float dt) = 0;

        /**
         * @brief This function finds and returns a tile designated by a position.
         *
         * @param pos Position of tile.
         * @returns Tile found at given position. Returns nullptr if no such tile exists.
         */
        inline Tile *findTile(GolfEngine::Vector2 pos) const
        {
            return this->tilemap->findTile(pos);
        }

        /**
         * @brief Render the scene by visiting all renderables and rendering them.
         *
         * @param visitor A RenderableVisitor responsible for rendering all objects.
         */
        inline void visit(GolfEngine::RenderableVisitor *visitor)
        {
            this->tilemap->visit(visitor);
        };

        /**
         * @brief Handle the collision between two entities.
         */
        virtual void handleCollision(GolfEngine::Collision &collision) = 0;

        /**
         * @brief End the current scene.
         *
         * @param winStatus True if the game ends in a win, false if the game ends in a loss.
         */
        virtual void endScene(bool winStatus) = 0;

        /**
         * @brief Key down event.
         */
        virtual void keyDown(sf::Keyboard::Key key) = 0;

        /**
         * @brief Key up event.
         */
        virtual void keyUp(sf::Keyboard::Key key) = 0;

        /**
         * @brief Check if the given is is being pressed.
         *
         * @returns True if the key is being pressed, false otherwise.
         */
        inline bool isKeyDown(sf::Keyboard::Key key)
        {
            return sf::Keyboard::isKeyPressed(key);
        }

        /**
         * @brief Mouse down event. Fires when the player presses down on a mouse button.
         *
         * @param event Mouse Button event.
         */
        virtual void mouseDown(sf::Event::MouseButtonEvent event) = 0;

        /**
         * @brief Mouse up event. Fires when the player presses up on a mouse button.
         *
         * @param event Mouse Button event.
         */
        virtual void mouseUp(sf::Event::MouseButtonEvent event) = 0;

        /**
         * @brief Mouse Move event. Fires when the player moves the mouse in focus of the Scene.
         *
         * @param event Mouse Move event.
         */
        virtual void mouseMove(sf::Event::MouseMoveEvent event) = 0;

        /**
         * @brief Pause the game.
         */
        void pause();

        /**
         * @brief Resume the game.
         */
        void resume();

        /**
         * @brief Get the current mouse position.
         *
         * @returns The current mouse position represented as a Vector2(x, y)
         */
        inline GolfEngine::Vector2 getMousePos() const
        {
            return this->mousePos;
        }

        /**
         * @brief Set the current mouse position.
         *
         * @param pos The new mouse position.
         * @note This is to be used by the encapsulating \ref GolfEngine::Window. DO NOT USE unless you want to MESS THINGS UP!
         */
        inline void setMousePos(GolfEngine::Vector2 pos)
        {
            this->mousePos = pos;
        }

    private:
        GolfEngine::Tilemap *tilemap;
        unsigned int max_side_length;
        GolfEngine::Vector2 mousePos;
    };
}

#endif