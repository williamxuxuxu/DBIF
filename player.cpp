#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    pl_side = side;
    board1 = new Board();
    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

// Use machine learning to figure out an ideal board metric such that a
// strategy faithful to the metric yields the highest win rate.
    if (opponentsMove != nullptr) {
        if (pl_side == WHITE) {
            board1->doMove(opponentsMove, BLACK);
        }
        else {
            board1->doMove(opponentsMove, WHITE);
        }
    }
    if (!board1->hasMoves(pl_side)) {
        return nullptr;
    }
    double max_score = -64.0;
    Move *max_move = new Move(0,0);
    
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            Board *temp = board1->copy();
            Move *curr_move = new Move(i,j);
            if (temp->checkMove(curr_move, pl_side)) {
                if (temp->boardScore(curr_move, pl_side) > max_score) {
                    max_move = curr_move;
                    max_score = temp->boardScore(curr_move, pl_side);
                }
            }
        }
    }
    board1->doMove(max_move, pl_side);
    return max_move;
// We will primaily try to write a machine learning based AI that will determine
// moves.
//
// Here's a test comment to see how git deals with multiple versions
}
