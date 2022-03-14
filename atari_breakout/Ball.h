//
// Created by bendi on 2022. 03. 12..
//

#ifndef BRICK_GAME_BALL_H
#define BRICK_GAME_BALL_H


#include "Player.h"

class Ball {
    float vX, vY;
    bool lost;
    Player *p;

public:
    float pX, pY;
    Ball(Player *p);

    void render();

    void update();

    bool isLost();

    void invertY();

    void reset();
};


#endif //BRICK_GAME_BALL_H
