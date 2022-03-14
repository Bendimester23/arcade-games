//
// Created by bendi on 2022. 03. 12..
//

#ifndef BRICK_GAME_CONFIG_H
#define BRICK_GAME_CONFIG_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define WINDOW_TITLE "Atari breakout"

#define DARK_MODE

#ifdef DARK_MODE
#define TEXT_COLOR WHITE
#define BG_COLOR BLACK
#define PLAYER_COLOR DARKPURPLE
#else
#define TEXT_COLOR BLACK
#define BG_COLOR WHITE
#define PLAYER_COLOR DARKPURPLE
#endif

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 20

#define PLAYER_Y 30

#define PLAYER_SPEED 400

#define BALL_SIZE 20
#define BALL_SPEED 200
#define BALL_COLOR RED

#define BRICK_COLOR DARKGREEN
#define BRICK_WIDTH 110
#define BRICK_HEIGHT 30

#endif //BRICK_GAME_CONFIG_H
