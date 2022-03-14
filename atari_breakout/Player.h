//
// Created by bendi on 2022. 03. 12..
//

#ifndef BRICK_GAME_PLAYER_H
#define BRICK_GAME_PLAYER_H


class Player {
public:
    float pos;

    Player();

    void render() const;

    void update();

    void reset();
};


#endif //BRICK_GAME_PLAYER_H
