/**
 * @file Circle.cpp
 * @brief This file contains definitions for the Circle class
 *
 * @author Willow Ciesialka
 * @date 2023-06-09
 */

#include "Circle.hpp"
#include <iostream>
using GolfEngine::Circle;

#define SQR(n) (n*n)

bool Circle::intersects(const GolfEngine::Line& line) const
{
    // Check if either of the line's endpoints are in the circle
    if(this->contains(line.a) || this->contains(line.b)){
        return true;
    }
    // Find the closest point on the line to the circle
    float dot = (this->getPosition() - line.a) * (line.b - line.a);
    dot /= SQR(line.length());
    float closestX = line.a.x + (dot * (line.b.x - line.a.x));
    float closestY = line.a.y + (dot * (line.b.y - line.a.y));
    GolfEngine::Vector2 closest(closestX, closestY);
    // Check to see if the closest point on the line
    // is within the bounds of the line's endpoints.
    if(!line.intersects(closest)){
        return false;
    }
    // Check if the closest point is within the circle.
    return this->contains(closest);
}

void Circle::render(sf::RenderWindow *window){
    sf::CircleShape shape(this->getRadius());
    shape.setFillColor(this->getColor());

    sf::Vector2f render_pos(this->getOrigin().x, this->getOrigin().y);

    shape.setPosition(render_pos);

    window->draw(shape);
}

#undef SQR