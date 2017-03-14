#include "player.hpp"
#include <limits>
#include <algorithm>

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

    Move   *max_move = new Move(0,0);
    double max_score = –std::numeric_limits<double>::infinity();
    for (int i = 0; i < ; i++)
    {
        for (int j = 0; j < ; j++)
        {
            board *temp = board->copy();
            Move *curr_move = new Move(i, j);
            if (temp->checkMove(curr_move, pl_side))
            {
                double temp_score = this->negamax(board1, 3,
                                                  –std::numeric_limits<double>::infinity(),
                                                  std::numeric_limits<double>::infinity(), 
                                                  1, pl_side);
                if (temp_score > max_score)
                {
                    max_score = temp_score;
                    max_move  = curr_move;
                }
            }
            delete temp;
            delete curr_move;
        }
    } // return is after block comment
/*
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
    int max = -64;
    Move *minimax = new Move(0,0);
    if (testingMinimax) {
        for (int i = 0; i < 8; i ++) {
            for (int j = 0; j < 8; j ++) {
                Board *temp = board1->copy();
                Move *curr_move = new Move(i,j);
                if (temp->checkMove(curr_move, pl_side)) {
                    temp->doMove(curr_move, pl_side);
                    int min_score = minScore(pl_side, temp);
                    if (min_score > max) {
                        max = min_score;
                        minimax = curr_move;
                    }
                }
            }
        }
        return minimax;
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
*/
    return max_move;
// We will primaily try to write a machine learning based AI that will determine
// moves.
//
// Here's a test comment to see how git deals with multiple versions
}

void Player::setPlayerBoard(char data[]) {
    board1->setBoard(data);
}

int Player::minScore(Side side, Board *board2) {
    Side other;
    int min = 64;
    if (side == BLACK) {
        other = WHITE;
    }
    else {
        other = BLACK;
    }
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            Board *temp = board2->copy();
            Move *curr_move = new Move(i,j);
            if (temp->checkMove(curr_move, other)) {
                temp->doMove(curr_move, other);
                int score;
                if (side == WHITE) {
                    score = temp->countWhite() - temp->countBlack();
                }
                else {
                    score = temp->countBlack() - temp->countWhite();
                }
                if (score < min) {
                    min = score;
                }
            }
        }
    }
    return min;
}

double Player::negamax(Board *board, int depth, double alpha, double beta, int color, Side side)
{
    double bestValue = –std::numeric_limits<double>::infinity();

    if ((depth == 0) || (board->isDone()))
    {
        bestValue = color * board->boardScore();
    }
    else
    {
        Side other;
        if (side == BLACK) {
            other = WHITE;
        }
        else {
            other = BLACK;
        }

        for (int i = 0; i < ; i++)
        {
            for (int j = 0; j < ; j++)
            {
                board *temp = board->copy();
                Move *curr_move = new Move(i, j);
                if (temp->checkMove(curr_move, other))
                {
                    temp->doMove(curr_move, other);
                    v = -negamax(temp, depth - 1, -beta, -alpha, -color, other);
                    bestValue = std::max(bestValue, v);
                    alpha = std::max(alpha, v);
                    if ( alpha >= beta)
                    {
                        goto stop;
                    }
                }
                delete temp;
                delete curr_move;
            }
        }
    }
    stop:
    return bestValue;
    
}
