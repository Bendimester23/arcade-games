//
// Created by bendi on 2022. 03. 12..
//

#ifndef BRICK_GAME_GAME_H
#define BRICK_GAME_GAME_H


#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include <raylib.h>

class Game {
public:
    Player player;
    Ball ball;
    Brick *bricks;
    char state;
    float countdown{};
    unsigned char health{};
    unsigned int currentFrame{};
    Texture2D heartTexture{};


    void render();

    void update();

    Game();
    void run();

    void reset(bool keepHealth);
};


#endif //BRICK_GAME_GAME_H
