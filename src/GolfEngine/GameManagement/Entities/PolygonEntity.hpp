/**
 * @file PolygonEntity.hpp
 * @brief Declerations for the PolygonEntity class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-09
 */

#ifndef POLYGONENTITY_H
#define POLYGONENTITY_H

#include "Entity.hpp"
#include "CircleEntity.hpp"
#include "../../Geometry/Shapes/Polygon.hpp"

namespace GolfEngine
{
    class PolygonEntity : public GolfEngine::Entity
    {
    public:
        PolygonEntity(Polygon *polygon) : shape(polygon), GolfEngine::Entity(){};
        PolygonEntity(Polygon *polygon, GolfEngine::Vector2 pos) : shape(polygon), GolfEngine::Entity(pos){};
        PolygonEntity(Polygon *polygon, GolfEngine::Vector2 pos, float rotation) : shape(polygon), GolfEngine::Entity(pos, rotation){};

        inline virtual void render(sf::RenderWindow *window)
        {
            this->shape->setOrigin(this->getOrigin());
            this->shape->render(window);
        };

        /**
         * @brief Check if the entity is colliding with another entity.
         *
         * @param other Entity to check collissions with.
         * @returns True if the entities are colliding, false otherwise.
         */
        inline bool intersects(const PolygonEntity* other) const{
            return this->getShape()->intersects(other->getShape());
        }

        inline bool intersects(const CircleEntity* other) const{
            return this->getShape()->intersects(other->getShape());
        }

        inline friend bool intersects(const CircleEntity* circle, const PolygonEntity* poly) {
            return poly->getShape()->intersects(circle->getShape());
        }

        /**
         * @brief Get the shape defining the entity.
         *
         * @returns The entity's defining shape.
         */
        inline GolfEngine::Polygon *getShape() const
        {
            return this->shape;
        }

        inline GolfEngine::EntityType getEntityType() const {
            return GolfEngine::EntityType::POLY;
        }

    private:
        GolfEngine::Polygon *shape;
    };
}

#endif