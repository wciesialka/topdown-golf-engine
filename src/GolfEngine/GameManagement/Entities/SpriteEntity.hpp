/**
 * @file SpriteEntity.hpp
 * @brief This file contains declerations for the Sprite class
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef SPRITEENTITY_H
#define SPRITEENTITY_H

#include "Entity.hpp"
#include "../../Geometry/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class SpriteEntity : public GolfEngine::Entity
    {
    public:
        SpriteEntity(sf::Texture tex) : GolfEngine::Entity()
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

        SpriteEntity(sf::Texture tex, GolfEngine::Vector2 pos) : GolfEngine::Entity(pos)
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

        SpriteEntity(sf::Texture tex, Vector2 pos, float rotation) : GolfEngine::Entity(pos, rotation)
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

        inline void render(sf::RenderWindow *window)
        {
            sf::Vector2f render_pos(this->getOrigin().x, this->getOrigin().y);
            this->sprite->setPosition(render_pos);
            this->sprite->setRotation(this->getRotation());

            window->draw(*this->sprite);
        };

    private:
        sf::Sprite *sprite;
    };
}

#endif