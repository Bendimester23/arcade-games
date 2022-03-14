//
// Created by bendi on 2022. 03. 13..
//

#ifndef BRICK_GAME_BRICK_H
#define BRICK_GAME_BRICK_H

#include <raylib.h>
#include "config.h"
#include "Ball.h"

class Brick {
    float pX, pY;
    Ball *b;
    bool broken;

public:
    Brick(float pX, float pY, Ball *b);

    void update();

    void render();

    void reset();

    bool isBroken();
};


#endif //BRICK_GAME_BRICK_H
