//
// Created by VuNAP on 11/23/2021.
//

#include "Animation.h"

Animation::Animation() {}

Animation::Animation( const std::vector<sf::Texture> &listTexture, float switchTime) : switchTime(switchTime),
                                                                                      listTexture(listTexture) {

    totalTime = 0;
    currentFrame = 0;
    setTexture(listTexture[currentFrame]);
}

void Animation::update(float deltaTime) {
    totalTime += deltaTime;
    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentFrame ++;
        if(currentFrame > listTexture.size() - 1)currentFrame = 0;
        setTexture(listTexture[currentFrame]);
    }
}
