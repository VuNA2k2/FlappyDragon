//
// Created by VuNAP on 11/23/2021.
//

#include "Dragon.h"

Dragon::Dragon() {}

Dragon::Dragon(const sf::Vector2f &pos, const Animation &animation, bool isDie) : pos(pos), animation(animation),
                                                                                  isDie(isDie) {
    this->animation.setPosition(this->pos);
}

Animation &Dragon::getAnimation(){
    return animation;
}

void Dragon::moveTop(float deltaTime) {
    animation.update(deltaTime);
    animation.move(0,-0.3);
    updatePos();
}

void Dragon::moveBot(float deltaTime) {
    animation.update(deltaTime);
    animation.move(0,0.05);
    updatePos();
}

void Dragon::updatePos() {
    this->pos = animation.getPosition();
}

void Dragon::setDie(sf::Vector2f pos) {

}

bool Dragon::checkDie(bool isDie) {
    this->isDie = isDie;
    return this->isDie;
}

bool Dragon::isDie1() const {
    return isDie;
}

const sf::Vector2f &Dragon::getPos() const {
    return pos;
}

void Dragon::setPos(const sf::Vector2f &pos) {
    Dragon::pos = pos;
}

