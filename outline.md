# Weiqi logic
https://stackoverflow.com/questions/5727/what-are-the-barriers-to-understanding-pointers-and-what-can-be-done-to-overcome

## Stone class
```cpp
class Stone {
    public:
        Color color; // Once a stone is given a colored, it's color does not change
        // What difference does this make?
        unsigned int x;
        unsigned int y;
        std::vector<Stone> stoneChain;
        std::vector<Stone> liberties;
        std::vector<Stone> neighbours;
        // std::vector<std::shared_ptr<Stone>> neighbours;
        // std::vector<std::shared_ptr<Stone>> stoneChain;

        Stone() {} // Default constructor 
        Stone(Color color_, int x_, int y_) : color(color_), x(x_), y(y_) {}

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
        // void initializeNeighbours() { 

        // }

        /**
         * Add all the stone's neighbours that are of the same color to the stoneChain
        */
        // void initializeStoneChain() {
            
        // }

        Color color() { return color; };
        int x() { return x; };
        int y() { return y; };
};
```
### Stone methods

## Board class
### Board methods

## Algorithms
### Capture stone

### 
