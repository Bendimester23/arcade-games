//
// Created by bendi on 2022. 03. 13..
//

#include "Brick.h"

Brick::Brick(float pX, float pY, Ball* b) {
    this->pX = pX;
    this->pY = pY;
    this->b = b;
    this->reset();
}

void Brick::render() {
    if (broken) return;

    DrawRectangle(pX, pY, BRICK_WIDTH, BRICK_HEIGHT, BRICK_COLOR);
}

void Brick::update() {
    if (broken) return;

    if (CheckCollisionRecs(Rectangle{b->pX, b->pY, BALL_SIZE, BALL_SIZE}, Rectangle{
            pX,
            pY,
            BRICK_WIDTH,
            BRICK_HEIGHT
    })) {
        broken = true;
        b->invertY();
    }
}

void Brick::reset() {
    this->broken = false;
}

bool Brick::isBroken() {
    return broken;
}
