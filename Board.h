#include"Tile.h"

struct Direction
{
    int x{0};
    int y{0};

    Direction& operator-()
    {
        x=-x;
        y=-y;

        return *this;
    }
};

class Board
{
    Tile board[4][4]{};

    Direction emptyTilePos{3,3};
public:
    Board();

    void randomizeBoard();

    bool checkWinCondition();

    bool move(Direction& dir);

    void display();

};
