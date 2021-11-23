//
// Created by VuNAP on 11/23/2021.
//

#ifndef FLAPPYDRAGON_DRAGON_H
#define FLAPPYDRAGON_DRAGON_H
#include "Animation.h"

class Dragon {
private:
    sf::Vector2f pos;
    Animation animation;
    bool isDie;
public:
    Dragon();

    Dragon(const sf::Vector2f &pos, const Animation &animation, bool isDie);

    Animation &getAnimation();

    void moveTop(float deltaTime);

    void moveBot(float deltaTime);

    void updatePos();

    void setDie(sf::Vector2f pos);

    bool checkDie(bool isDie);

    bool isDie1() const;

    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &pos);
};


#endif //FLAPPYDRAGON_DRAGON_H
