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
    this->state = 'm';
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

        this->update();

        BeginDrawing();

        this->render();

        EndDrawing();
    }

    CloseWindow();

    free(bricks);
}

void DrawCenteredText(std::string str, int x, int size) {
    DrawText(str.c_str(), WINDOW_WIDTH/2-MeasureText(str.c_str(), size)/2, x, size, TEXT_COLOR);
}

void Game::render() {
    if (this->state == 'm') {
        currentFrame++;
        DrawCenteredText("Breakout", 40, 60);
        DrawCenteredText("Press SPACE to start!", 250+sin(60*3.14*currentFrame)*20, 32);
        return;
    }

    for (int i = 0; i < 20; ++i) {
        bricks[i].render();
    }

    if (state == 'l') {
        DrawCenteredText("You ded af", 100, 50);
        DrawCenteredText("Press R to restart", 200, 32);
    } else if (state == 'w') {
        DrawCenteredText("Absolute legend", 100, 50);
        DrawCenteredText("Press R to restart", 200, 32);
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

    unsigned char score = 0;
    for (int i = 0; i < 20; ++i) {
        if (bricks[i].isBroken()) score++;
    }

    if (score == 20) {
        this->state = 'w';
    }
    DrawText(std::to_string(score).c_str(), 55, 50, 36, TEXT_COLOR);
}

void Game::update() {
    if (state == 'm') {
        if (IsKeyPressed(KEY_SPACE)) this->state = 'g';
        return;
    }
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
