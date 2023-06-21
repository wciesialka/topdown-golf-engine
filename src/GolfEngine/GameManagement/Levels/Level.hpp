/**
 * @file Level.hpp
 * @brief This file contains declerations for the Level abstract class.
 * 
 * @date 2023-06-16
 * @author Willow Ciesialka
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "../Scene.hpp"
#include "../Collision.hpp"
#include "../Tile.hpp"

namespace GolfEngine {
    class Level : public GolfEngine::Scene {
        public:
            Level() : GolfEngine::Scene() {
            };
            Level(unsigned int side_length) : GolfEngine::Scene(side_length) {
            };

            /**
             * @brief Initialize the level.
             * 
             * This function should handle everything that needs to happen when initializing the level -
             * this means loading the tilemap, adding to it, et cetera.
            */
            virtual void initialize() = 0;

            virtual void levelCollisions(GolfEngine::Collision& collision) = 0;

            void onCollision(GolfEngine::Collision& collision) override;

            /**
             * @brief Set the target position.
             * 
             * @param pos Position
            */
            void setTarget(const GolfEngine::Vector2& pos) {
                this->target = pos;
            }

            /**
             * @brief Get the target position.
             * 
             * @returns Target pos.
            */
            GolfEngine::Vector2 getTarget() const {
                return this->target;
            }

            /**
             * @brief Mouse down event. Fires when the player presses down on a mouse button.
             *
             * @param event Mouse Button event.
             */
            void onMouseDown(sf::Event::MouseButtonEvent &event) override;

            /**
             * @brief Mouse up event. Fires when the player presses up on a mouse button.
             *
             * @param event Mouse Button event.
             */
            void onMouseUp(sf::Event::MouseButtonEvent &event) override;

            /**
             * @brief Mouse Move event. Fires when the player moves the mouse in focus of the Scene.
             *
             * @param event Mouse Move event.
             */
            void onMouseMove(sf::Event::MouseMoveEvent &event) override;            

            void applyPlayerForce(const GolfEngine::Vector2& force);

            /**
             * @brief Frame update
             *
             * @param dt Time since last frame update (in ms)
             */
            void frameUpdate(float dt);
        private:
            GolfEngine::Vector2 target;

    };
}

#endif