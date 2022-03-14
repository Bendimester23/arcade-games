//
// Created by bendi on 2022. 03. 12..
//

#include "Ball.h"
#include "config.h"
#include <raylib.h>

Ball::Ball(Player *p) {
    this->reset();
    this->p = p;
}

void Ball::render() {
    DrawRectangle(pX, pY, BALL_SIZE, BALL_SIZE, BALL_COLOR);
}

void Ball::update() {
    pX += vX*BALL_SPEED*GetFrameTime();
    pY += vY*BALL_SPEED*GetFrameTime();

    if (pX+BALL_SIZE > WINDOW_WIDTH || pX < 0) vX *= -1;
    if (pY < 0) vY *= -1;

    if (pY+BALL_SIZE > WINDOW_HEIGHT-PLAYER_HEIGHT-PLAYER_Y) {
        if (pX+BALL_SIZE > p->pos && pX < p->pos+PLAYER_WIDTH) vY *= -1;
        else lost = true;
    }
}

bool Ball::isLost() {
    return lost;
}

void Ball::invertY() {
    this->vY *= -1;
}

void Ball::reset() {
    this->pX = WINDOW_WIDTH/2-BALL_SIZE/2;
    this->pY = WINDOW_HEIGHT/2-BALL_SIZE/2;
    this->vX = 1;
    this->vY = -1;
    this->lost = false;
}
