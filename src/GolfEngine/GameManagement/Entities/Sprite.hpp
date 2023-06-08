/**
 * @file Sprite.hpp
 * @brief This file contains declerations for the Sprite class
 *
 * @author Willow Ciesialka
 * @date 2023-06-07
 */

#ifndef SPRITE_H
#define SPRITE_H

#include "Entity.hpp"
#include "../../Geometry/Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace GolfEngine
{
    class Sprite : public GolfEngine::Entity
    {
    public:
        Sprite(sf::Texture tex) : GolfEngine::Entity()
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

        Sprite(sf::Texture tex, GolfEngine::Vector2 pos) : GolfEngine::Entity(pos)
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

        Sprite(sf::Texture tex, Vector2 pos, float rotation) : GolfEngine::Entity(pos, rotation)
        {
            this->sprite = new sf::Sprite;
            this->sprite->setTexture(tex);
        }

    private:
        sf::Sprite *sprite;
    };
}

#endif