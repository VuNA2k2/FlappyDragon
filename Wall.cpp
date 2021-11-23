//
// Created by VuNAP on 11/23/2021.
//

#include "Wall.h"

std::vector<std::pair<sf::Vector2f, sf::Vector2f>> Wall::getPosWall() {
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> listPos;
    for(int i = 0 ; i < listWall.size(); i ++){
        listPos.push_back({listWall[i].first.getPosition(),listWall[i].second.getPosition()});
    }
    return listPos;
}

void Wall::updateWall(float deltaTime) {
    for(int i = 0 ; i < listWall.size(); i ++){
        listWall[i].first.move(-deltaTime,0);
        listWall[i].second.move(-deltaTime,0);
    }
    if(listWall[0].first.getPosition().x <= - 140){
        listWall.erase(listWall.begin(),listWall.begin()+1);
        int height1 = rand() % (700);
        sf::RectangleShape shape1;
        shape1.setSize(sf::Vector2f(140,height1));
        shape1.setPosition(sf::Vector2f(listWall[listWall.size()-1].first.getPosition().x + 440,0));
        shape1.setFillColor(sf::Color::Cyan);
        sf::RectangleShape shape2;
        shape2.setSize(sf::Vector2f(140,1080));
        shape2.setPosition(sf::Vector2f(listWall[listWall.size()-1].first.getPosition().x + 440,(height1 + 300)));
        shape2.setFillColor(sf::Color::Cyan);
        listWall.push_back({shape1,shape2});
    }
}

Wall::Wall(int number) : number(number) {
    for(int i = 0 ; i < this->number ; i ++){
        int height1 = rand() % (700);
        sf::RectangleShape shape1;
        shape1.setSize(sf::Vector2f(140,height1));
        shape1.setPosition(sf::Vector2f(500 + (440 * i),0));
        shape1.setFillColor(sf::Color::Cyan);
        sf::RectangleShape shape2;
        shape2.setSize(sf::Vector2f(140,1080));
        shape2.setPosition(sf::Vector2f(500 + (440 * i),(height1 + 300)));
        shape2.setFillColor(sf::Color::Cyan);
        listWall.push_back({shape1,shape2});
    }
}

Wall::Wall() {}

std::vector<std::pair<sf::RectangleShape, sf::RectangleShape>> &Wall::getWalls() {
    return this->listWall;
}

bool Wall::checkCollision(sf::Vector2f pos) {
    for(int i = 0 ; i < listWall.size(); i++){
        if(pos.x + 106 >= listWall[i].first.getPosition().x && pos.x <= listWall[i].first.getPosition().x + listWall[i].first.getSize().x && pos.y + 20 <= listWall[i].first.getPosition().y + listWall[i].first.getSize().y){
            return true;
        }
        if(pos.x + 106 >= listWall[i].second.getPosition().x && pos.x <= listWall[i].second.getPosition().x + listWall[i].second.getSize().x && pos.y + 106 >= listWall[i].second.getPosition().y){
            return true;
        }
    }
    return false;
}
