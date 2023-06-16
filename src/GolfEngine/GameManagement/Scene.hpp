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
        Scene() : tilemap(new Tilemap()) {};
        Scene(unsigned int side_length) : tilemap(new Tilemap(side_length)) {};
        ~Scene() {
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
        inline bool addTile(Tile *tile) {
            return this->tilemap->addTile(tile);
        };

        /**
         * @brief Handle event
         */
        void handleEvent(sf::Event event);

        /**
         * @brief Frame update
         *
         * @param dt Time since last frame update (in ms)
         */
        virtual void frameUpdate(float dt);

        /**
         * @brief This function finds and returns a tile designated by a position.
         *
         * @param pos Position of tile.
         * @returns Tile found at given position. Returns nullptr if no such tile exists.
         */
        inline Tile *findTile(GolfEngine::Vector2 pos) const {
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
        void handleCollision(GolfEngine::Collision collision);

        /**
         * @brief End the current scene.
        */
        void endScene();

    private:
        GolfEngine::Tilemap* tilemap;
        unsigned int max_side_length;
    };
}

#endif