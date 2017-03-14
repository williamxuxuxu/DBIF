#ifndef __BOARD_H__
#define __BOARD_H__

#include <math.h>
#include <bitset>
#include "common.hpp"
using namespace std;

class Board {

private:
    bitset<64> black;
    bitset<64> taken;
    double board_heur[8][8] = {{1,-0.5,0.5,0.5,0.5,0.5,-0.5,1},
                              {-0.5,-1,0,0,0,0,-1,-0.5},
                              {0.5,0,0,0,0,0,0,0.5},
                              {0.5,0,0,0,0,0,0,0.5},
                              {0.5,0,0,0,0,0,0,0.5},
                              {0.5,0,0,0,0,0,0,0.5},
                              {-0.5,-1,0,0,0,0,-1,-0.5},
                              {1,-0.5,0.5,0.5,0.5,0.5,-0.5,1}};
/*    double board_heur[8][8] = {{1,-0.5,0.5,0.5,0.5,0.5,-0.5,1},
                              {-0.5,-1,-0.25,-0.25,-0.25,-0.25,-1,-0.5},
                              {0.5,-0.25,0.25,0.1,0.1,0.25,-0.25,0.5},
                              {0.5,-0.25,0.1,0,0,0.1,-0.25,0.5},
                              {0.5,-0.25,0.1,0,0,0.1,-0.25,0.5},
                              {0.5,-0.25,0.25,0.1,0.1,0.25,-0.25,0.5},
                              {-0.5,-1,-0.25,-0.25,-0.25,-0.25,-1,-0.5},
                              {1,-0.5,0.5,0.5,0.5,0.5,-0.5,1}}; */

    bool occupied(int x, int y);
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
    bool onBoard(int x, int y);

public:
    Board();
    ~Board();
    Board *copy();

    bool isDone();
    bool hasMoves(Side side);
    bool checkMove(Move *m, Side side);
    void doMove(Move *m, Side side);
    int count(Side side);
    int countBlack();
    int countWhite();
    double boardScore(Move *m, Side side);
    void setBoard(char data[]);
};

#endif
