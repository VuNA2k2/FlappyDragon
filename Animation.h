//
// Created by VuNAP on 11/23/2021.
//

#ifndef FLAPPYDRAGON_ANIMATION_H
#define FLAPPYDRAGON_ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation : public sf::Sprite{
private:
    float totalTime, switchTime;
    int currentFrame;
    std::vector<sf::Texture> listTexture;
public:
    Animation();

    Animation(const std::vector<sf::Texture> &listTexture, float switchTime);

    void update(float deltaTime);
};


#endif //FLAPPYDRAGON_ANIMATION_H
