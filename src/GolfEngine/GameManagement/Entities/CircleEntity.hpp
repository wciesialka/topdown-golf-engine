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
        CircleEntity(Circle *circle) : shape(circle), GolfEngine::Entity(){};
        CircleEntity(Circle *circle, GolfEngine::Vector2 pos) : shape(circle), GolfEngine::Entity(pos){};
        CircleEntity(Circle *circle, GolfEngine::Vector2 pos, float rotation) : shape(circle), GolfEngine::Entity(pos, rotation){};

        inline virtual void render(sf::RenderWindow *window) {
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