/**
 * @file Tile.hpp
 * @brief This file contains the decleration for the Tile class
 *
 * @author Willow Ciesialka
 * @date 2023-06-06
 */

#ifndef TILE_H
#define TILE_H

#include "../Geometry/Vector2.hpp"
#include "Entities/Entity.hpp"
#include "../Rendering/Renderable.hpp"
#include "../Rendering/RenderableVisitor.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GolfEngine
{
    class Tile : public Renderable
    {
    public:
        static const unsigned int TILE_SIZE = 64;

        Tile() : entities(GolfEngine::Entity::EntityList()),
                 GolfEngine::Renderable(){};
        Tile(GolfEngine::Vector2 pos) : entities(GolfEngine::Entity::EntityList()),
                                        GolfEngine::Renderable(pos){};
        /**
         * @brief This function adds an entity to the tile.
         *
         * @param ent The entity to add to the tile.
         * @returns True if the addition was a success, false otherwise.
         */
        bool addEntity(GolfEngine::Entity *ent);

        /**
         * @brief Remove an entity from the tile.
         *
         * @param[in] ent The entity to remove from the tile.
         * @returns True if the removal was a success, false otherwise.
         */
        bool removeEntity(GolfEngine::Entity *ent);

        /**
         * @brief Check if the tile contains an entity.
         *
         * @param[in] ent The entity to find.
         * @returns True if the entity is in the tile, false otherwise.
         */
        inline bool containsEntity(GolfEngine::Entity *ent) { return this->findEntity(ent) != this->entities.end(); };

        /**
         * @brief Render the tile
         *
         * @param window Window to render onto.
         */
        virtual void render(sf::RenderWindow *window);

        virtual void visit(GolfEngine::RenderableVisitor *visitor)
        {
            this->render(visitor->getWindow());
            for (GolfEngine::Entity *entity : this->entities)
            {
                entity->visit(visitor);
            }
        }

    private:
        GolfEngine::Entity::EntityList entities;

        /**
         * @brief Find the entity in the Tile, if it exists.
         *
         * @param[in] entity Entity to find
         * @returns The entity, if it was found.
         */
        GolfEngine::Entity::EntityList::iterator findEntity(GolfEngine::Entity *entity);
    };
}

#endif