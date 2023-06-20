/**
 * @file TileGeometry.cpp
 * @brief This file contains definitions for the TileGeometry class
 *
 * @date 2023-06-20
 * @author Willow Ciesialka
 */

#include "TileGeometry.hpp"

using GolfEngine::TileGeometry;

void TileGeometry::render(sf::RenderWindow *window)
{
    // First, render base layer
    float tile_length = (float)(TileGeometry::TILE_SIZE);
    GolfEngine::Vector2 tile_origin = this->getOrigin();

    sf::RectangleShape render_ground(sf::Vector2f(tile_length, tile_length));
    render_ground.setPosition(sf::Vector2f(tile_origin.x, tile_origin.y));
    render_ground.setFillColor(sf::Color(TileGeometry::GRASS_COLOR));
    window->draw(render_ground);
    // Second, render walls
    for (GolfEngine::Line &wall : this->line_geometry)
    {
        GolfEngine::Vector2 render_a = wall.a + tile_origin;
        GolfEngine::Vector2 render_b = wall.b + tile_origin;

        sf::Vertex render_line[2];

        render_line[1] = sf::Vertex(sf::Vector2f(render_a.x, render_a.y));
        render_line[1].color = sf::Color(TileGeometry::WALL_COLOR);
        render_line[2] = sf::Vertex(sf::Vector2f(render_b.x, render_b.y));
        render_line[2].color = sf::Color(TileGeometry::WALL_COLOR);

        window->draw(render_line, 2, sf::Lines);
    }
    // Visitor will take care of the rest!
}

void TileGeometry::visit(GolfEngine::RenderableVisitor* visitor){
    // First, render ourselves.
    this->render(visitor->getWindow());
    // Then, render the holes.
    for (GolfEngine::Circle& circle_hole : this->circle_geometry){
        circle_hole.visit(visitor);
    }
    for (GolfEngine::Polygon& polyhole : this->polygon_geometry){
        polyhole.visit(visitor);
    }
}