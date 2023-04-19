#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <colors.h>

class Player {
    public:
        int points;

        Player() {}
        Player(int points_) : points(points_) {}
};

class BlackPlayer : Player {

};

class WhitePlayer : Player {

};

class Board {
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

        void placeStone(Stone stone, int x, int y) {
            if (isMoveLegal(stone, x, y)) {
                if (turn) {
                    stone = Stone(WHITE, x, y);
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
                for (Stone member : stone.stoneChain()) {
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
        std::vector<int> stoneChain;

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

        void initializeLiberties() {

        }

        void initializeNeighbours() {

        }

        void initializeStoneChain() {
            
        }

        Color color() { return color; };
        int x() { return x; };
        int y() { return y; };
};

#endif