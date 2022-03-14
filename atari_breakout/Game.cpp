//
// Created by bendi on 2022. 03. 12..
//

#include "Game.h"
#include "config.h"
#include <cmath>
#include <string>

Game::Game(): player(), ball(&player) {
    bricks = (Brick*)(void*)malloc(sizeof(Brick)*20);
    reset(false);
}

void Game::run() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    this->heartTexture = LoadTexture("./assets/heart.png");

    SetTargetFPS(60);

    for (int i = 0; i < 20; ++i) {
        bricks[i] = Brick(i%5*(BRICK_WIDTH+10)+20, i/5*(BRICK_HEIGHT+10)+10, &ball);
    }

    while (!WindowShouldClose()) {
        ClearBackground(BG_COLOR);
        BeginDrawing();

        this->update();
        this->render();

        EndDrawing();
    }

    free(bricks);
}

void Game::render() {

    for (int i = 0; i < 20; ++i) {
        bricks[i].render();
    }

    if (state == 'l') {
        DrawText("You ded af", 100, 100, 32, TEXT_COLOR);
    } else if (state == 'w') {
        DrawText("Absolute legend", 100, 100, 32, TEXT_COLOR);
    }

    ball.render();
    player.render();

    if (countdown > 0 && state == 'g') {
        DrawText(std::to_string((int)std::ceil((float)countdown)).c_str(), 100, 100, 32, TEXT_COLOR);
    }

    //How to draw a heart 101 by Bendi
//    DrawRectanglePro(Rectangle{15, 10, 26, 16}, Vector2{0,0}, 45, BLACK);
//    DrawRectanglePro(Rectangle{30, 10, 16, 26}, Vector2{0,0}, 45, BLACK);
//
//    DrawRectanglePro(Rectangle{15, 13, 22, 12}, Vector2{0,0}, 45, red);
//    DrawRectanglePro(Rectangle{30, 13, 12, 22}, Vector2{0,0}, 45, red);

    DrawTextureEx(heartTexture, Vector2{10, 10}, 0, 3, TEXT_COLOR);

    DrawText(std::to_string(health).c_str(), 55, 10, 36, TEXT_COLOR);
    u_short points = 0;
    for (int i = 0; i < 20; ++i) {
        if (bricks[i].isBroken()) points++;
    }
    if (points == 20) {
        this->state = 'w';
    }
    DrawText(std::to_string(points).c_str(), 55, 50, 36, TEXT_COLOR);
}

void Game::update() {
    if (countdown > 0) {
        countdown -= GetFrameTime();
        return;
    }
    if (IsKeyPressed(KEY_R)) this->reset(false);
    if (state != 'g') return;
    ball.update();
    if (ball.isLost()) {
        this->health--;
        reset(true);
    }
    if (health == 0) {
        this->state = 'l';
    }
    player.update();

    for (int i = 0; i < 20; ++i) {
        bricks[i].update();
    }

}

void Game::reset(bool keepHealth) {
    ball.reset();
    player.reset();
    this->state = 'g';
    this->countdown = 3;
    if (!keepHealth) {
        this->health = 3;
        for (int i = 0; i < 20; ++i) {
            bricks[i].reset();
        }
    }
}
