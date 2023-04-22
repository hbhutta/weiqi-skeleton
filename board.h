#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <memory> 
#include <vector>
#include <colors.h>

class Player {
    public:
		bool color;
		bool turn;
        int points;

        Player() {}
        Player(bool color_, bool turn_, int points_) : color(color_), turn(turn_),  points(points_) {}
};

/** We will want to determine who has the turn if a player chooses to pass.
 * For now, we can make 'turn' an attribute of the player class, and in the 
 * subclasses, the turn will be initialized to indicate that Black always plays first
 * Equivalently, we don't have to make the subclasses, if we just inlcude an attribute that
 * distinguishes a player as black or white
 */

// class BlackPlayer : Player {
// 	public:
// 		BlackPlayer() {} // Default constructor
// };
// 
// class WhitePlayer : Player {
// 	public:
// 		WhitePlayer() {} // Default constructor
// };

class Board { // Eventually add komi and handicap mechanism as well.
    public:
        static const int BOARD_SIZE = 19; // Must be odd
        bool occupied[BOARD_SIZE][BOARD_SIZE];
        Stone board[BOARD_SIZE][BOARD_SIZE];
        bool turn;

        Board() {} // Default constructor
        Board() {
            initializeBoard();
        }

        void initializeBoard() {
            for (int y = 0; y < BOARD_SIZE; y++) {
                for (int x = 0; x < BOARD_SIZE; x++) {
                    occupied[y][x] = false; // All points are non-occupied initially
                    board[y][x] = Stone(EMPTY, x, y); // There are no stones initially
                }
            }
        }

        /**
         * The maximum possible neighbours are four, in the cardinal directions.
         * First check that in each of these spots, a stone of the same color is placed.
         * There might be conflict with the check legal move function, if move is suicidal..
        */
        void initializeStoneNeighbours(Stone stone) {
            stone.liberties.stoneChain.
        }

        void initializeStoneLiberties(Stone stone) {

        }

        void placeStone(Stone stone, int x, int y) {
            if (isMoveLegal(stone, x, y)) {
                if (turn) {
                    stone = Stone(WHITE, x, y);
                    initializeStoneLiberties(stone);
                    initializeStoneNeighbours(stone);
                }
                else {
                    stone = Stone(BLACK, x, y);
                } 
                occupied[y][x] = true;
                board[y][x] = stone;    
            }
        }

        bool isMoveLegal(Stone stone, int x, int y) {
            return (isMoveWithinBounds(x, y) and not(isMoveSuicidal(stone, x, y)));
        }

        /**
         * Return true if 0 <= x,y <= 19
        */
        bool isMoveWithinBounds(int x, int y) {
            bool isXInBounds = (x >= 0) and (x <= 19);
            bool isYInBounds = (y >= 0) and (y <= 19);
            return isXInBounds and isYInBounds;
        }

        /**
         * If all the neighbours around the given position are of the opposite color,
         * the move is suicidal
        */
        bool isMoveSuicidal(Stone stone, int x, int y) {
            
        }

        void capture(Stone stone) {
            if (stone.color() != EMPTY) {
                int capturer_color;
                if (stone.color() == BLACK) {
                    capturer_color = WHITE;
                }
                else if (stone.color() == WHITE) {
                    capturer_color = BLACK;
                }
                for (Stone member : stone.stoneChain) {
                    stone.setColor(EMPTY);
                    occupied[stone.y()][stone.x()] = false;
                }
            }
            
        }
};

class Stone {
    public:

        Color color;
        int x;
        int y;
        StoneChain stoneChain;
        StoneChain liberties;
        StoneChain neighbours;

        Stone() {} // Default constructor 
        Stone(Color color_, int x_, int y_) : color(color_), x(x_), y(y_) {
            initializeLiberties();
            initializeNeighbours();
            initializeStoneChain();
        }

        Color color() { return color; };
        void setColor(Color color_) { this->color = color_; };

        int x() { return x; };
        void setX(int x_) { this->x = x_; };

        int y() { return y; };
        void setY(int y_) { this->y = y_; };

        /**
         * This method should be in board, because the liberties
         * the stone will have are determined at placement.
        */
        // void initializeLiberties() {

        // }

        /**
         * This method should be in board, because the neighbours
         * can only be initialized when the stone is placed.
        */
        void initializeNeighbours() { 

        }

        /**
         * Add all the stone's neighbours that are of the same color to the stoneChain
        */
        void initializeStoneChain() {
            
        }

        Color color() { return color; };
        int x() { return x; };
        int y() { return y; };
};

/**
 * StoneChain is ListOf: Stone.
 * To StoneChain, we can:
 * - add/remove a Stone
 * - clear the StoneChain
*/
class StoneChain : Stone {
    public:
        StoneChain() {} // Default constructor
        StoneChain(std::shared_ptr<Stone> stone) { add(stone); }
        
        void clear() {
            stoneChain.clear(); 
        }
        
        void add(std::shared_ptr<Stone> stone) {
            stoneChain.push_back(stone);
        }

    public:
        std::vector<std::shared_ptr<Stone>> stoneChain;
};

#endif
