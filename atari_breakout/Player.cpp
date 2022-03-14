//
// Created by bendi on 2022. 03. 12..
//

#include "Player.h"
#include "config.h"
#include <raylib.h>
#include <raymath.h>

Player::Player() {
    this->reset();
}

void Player::render() const {
    DrawRectangle(pos, WINDOW_HEIGHT-PLAYER_Y-PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_COLOR);
}

void Player::update() {
    if (IsKeyDown(KEY_A)) {
        this->pos = Clamp(pos-PLAYER_SPEED*GetFrameTime(), 0, WINDOW_WIDTH-PLAYER_WIDTH);
    }
    if (IsKeyDown(KEY_D)) {
        this->pos = Clamp(pos+PLAYER_SPEED*GetFrameTime(), 0, WINDOW_WIDTH-PLAYER_WIDTH);
    }
}

void Player::reset() {
    pos = (WINDOW_WIDTH / 2)-(PLAYER_WIDTH/2);
}
