//
// Created by VuNAP on 11/23/2021.
//

#ifndef FLAPPYDRAGON_WALL_H
#define FLAPPYDRAGON_WALL_H
#include <SFML/Graphics.hpp>

class Wall {
private:
    int number;
    std::vector<std::pair<sf::RectangleShape,sf::RectangleShape>> listWall;
    float switchTime , totalTime;
public:
    Wall();

    Wall(int number);

    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> getPosWall();

    void updateWall(float deltaTime);

    std::vector<std::pair<sf::RectangleShape, sf::RectangleShape>>& getWalls();

    bool checkCollision(sf::Vector2f pos);
};


#endif //FLAPPYDRAGON_WALL_H
