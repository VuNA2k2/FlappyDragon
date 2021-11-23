#include "Animation.h"
#include "Dragon.h"
#include "Wall.h"


sf::RenderWindow window(sf::VideoMode(1920,1080),"Flappy Dragon",sf::Style::Close | sf::Style::Resize);
Animation animation;
Dragon dragon;
sf::Texture texture1;
sf::Texture texture2;
sf::Sprite sprite1;
sf::Sprite sprite2;
sf::Texture texture3;
sf::Sprite sprite3;
Wall walls;

void init(){
    texture1.loadFromFile("background.png");
    sprite1.setTexture(texture1);
    sprite1.setPosition(0,0);
    texture2.loadFromFile("background.png");
    sprite2.setTexture(texture2);
    sprite2.setPosition(3840,0);
    std::vector<sf::Texture> listTexture;
    for(int i = 0 ; i < 3 ; i ++){
        sf::Texture texture;
        texture.loadFromFile("test.png",sf::IntRect(106*i,212,106,106));
        listTexture.push_back(texture);
    }
    animation = Animation(listTexture, 7);
    dragon = Dragon(sf::Vector2f(200,423),animation, false);
    walls = Wall(8);
    texture3.loadFromFile("gameover.png");
    sprite3.setTexture(texture3);
}


float totalTime = 0;


void drawBackground(){
    totalTime += 0.02;
    window.draw(sprite1);
    window.draw(sprite2);
    sprite1.move(-0.02,0);
    sprite2.move(-0.02,0);
    if(totalTime >= 3840){
        sprite1.setPosition(0,0);
        sprite2.setPosition(3840,0);
        totalTime -= 3840;
    }
}

void drawWall(){
    for(int i = 0 ; i < walls.getWalls().size() ; i ++){
        window.draw(walls.getWalls()[i].first);
        window.draw(walls.getWalls()[i].second);
    }
    walls.updateWall(0.02);
}

int main() {
    init();
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))dragon.moveTop(0.01);

        window.clear();
        if(dragon.checkDie(walls.checkCollision(dragon.getPos()))){
            window.draw(sprite3);
        } else{
            drawBackground();
            drawWall();
            window.draw(dragon.getAnimation());
            dragon.moveBot(0.01);
        }
        window.display();
    }
}
