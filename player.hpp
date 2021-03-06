#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    double negamax(Board *board, int depth, double alpha, double beta, int color, Side side);
    int minScore(Side side, Board *board2);
    void setPlayerBoard(char data[]);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Board *board1;
    Side pl_side;
    
};

#endif
