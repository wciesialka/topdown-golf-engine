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
#include "TileGeometry.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>

namespace GolfEngine
{
    class Tile : public GolfEngine::Renderable
    {
    public:
        Tile() : GolfEngine::Renderable()
        {
            this->entities = new GolfEngine::Entity::EntityList();
            this->geometry = new GolfEngine::TileGeometry(GolfEngine::Vector2::zero);
        }

        Tile(const GolfEngine::Vector2 &pos) : GolfEngine::Renderable(pos)
        {
            this->entities = new GolfEngine::Entity::EntityList();
            this->geometry = new GolfEngine::TileGeometry(pos);
        }

        ~Tile()
        {
            delete this->entities;
            delete this->geometry;
        }

        /**
         * @brief Check whether an entity is within bounds of the tile.
         *
         * @param ent Entity to check
         * @returns True if the entity is within bounds, False otherwise.
         */
        inline bool isEntityWithinBounds(const GolfEngine::Entity* ent) const {
            GolfEngine::Vector2 entity_point = this->worldToLocal(ent->getOrigin());
            return this->getTileGeometry()->isPointValid(entity_point);
        }

        /**
         * @brief This function adds an entity to the tile.
         *
         * @param ent The entity to add to the tile.
         * @returns True if the addition was a success, false otherwise.
         * @throws std::out_of_range If the entity is outside of Tile boundaries.
         */
        inline void addEntity(GolfEngine::Entity *ent) {
            if(!isEntityWithinBounds(ent)){
                throw std::out_of_range("Cannot add entity with an origin that is outside of Tile's bounds.");
            }
            this->entities->push_back(ent);
        };

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
        inline bool containsEntity(GolfEngine::Entity *ent) { return this->findEntity(ent) != this->entities->end(); };

        /**
         * @brief Initialize the tile's collisions. Tile geometry should be defined here.
         */
        virtual void initialize() = 0;

        /**
         * @brief Get a pointer to the Tile's geometry.
         */
        inline GolfEngine::TileGeometry *getTileGeometry() const
        {
            return this->geometry;
        }

        /**
         * @brief Render the tile
         *
         * @param window Window to render onto.
         */
        void render(sf::RenderWindow *window){ 
            // DO nothing
            if(window == nullptr){ return; }
            return; /* Do nothing. The visitor will handle it all... */
        };

        void visit(GolfEngine::RenderableVisitor *visitor)
        {
            this->getTileGeometry()->visit(visitor);
            for (GolfEngine::Entity *entity : *this->entities)
            {
                entity->visit(visitor);
            }
        }

        GolfEngine::Entity::EntityList* getEntities() const {
            return this->entities;
        }

    private:
        GolfEngine::Entity::EntityList *entities;
        GolfEngine::TileGeometry *geometry;

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