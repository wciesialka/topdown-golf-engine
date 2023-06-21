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
        private:
    };
}

#endif