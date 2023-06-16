/**
 * @file CircleEntity.hpp
 * @brief Declerations for the CircleEntity class.
 *
 * TODO: Find some way to abstract this further? Due to the difference in
 * implementations of intersection detection in Polygons and Circles, we
 * can't just abstract it to a generic intersects(Shape), and that reflects
 * here on us not being able to have a generic ShapeEntity class.
 *
 * @author Willow Ciesialka
 * @date 2023-06-09
 */

#ifndef CIRCLEENTITY_H
#define CIRCLEENTITY_H

#include "Entity.hpp"
#include "../../Geometry/Shapes/Circle.hpp"

namespace GolfEngine
{
    class CircleEntity : public GolfEngine::Entity
    {
    public:
        CircleEntity(float radius) : GolfEngine::Entity()
        {
            this->shape = new GolfEngine::Circle(radius);
        }
        CircleEntity(float radius, GolfEngine::Vector2 pos) : GolfEngine::Entity(pos)
        {
            this->shape = new GolfEngine::Circle(radius);
        }
        CircleEntity(float radius, GolfEngine::Vector2 pos, float rotation) : GolfEngine::Entity(pos, rotation)
        {
            this->shape = new GolfEngine::Circle(radius);
        }

        ~CircleEntity()
        {
            delete this->shape;
        }

        inline virtual void render(sf::RenderWindow *window)
        {
            this->shape->setOrigin(this->getOrigin());
            this->shape->render(window);
        };

        /**
         * @brief Get the shape defining the entity.
         *
         * @returns The entity's defining shape.
         */
        inline GolfEngine::Circle *getShape() const
        {
            return this->shape;
        }

    private:
        GolfEngine::Circle *shape;
    };
}

#endif