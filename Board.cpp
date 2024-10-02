#include"Board.h"
#include<utility>
#include"random.h"


Board::Board()
{
    int val{1};
    for (std::size_t i{0}; i < 4; ++i)
    {
        for (std::size_t j{0}; j < 4; ++j)
        {   
            if(i==3 && j==3) continue;
            board[i][j]=val;
            ++val;
        }
    }
}

bool Board::checkWinCondition()
{
    int val{1};
    for (std::size_t i{0}; i < 4; ++i)
    {
        for (std::size_t j{0}; j < 4; ++j)
        {
            if(i==3 && j==3) continue;     
            if(board[i][j].getValue()!=static_cast<int>(val)) return false;
            ++val;
        }
    }
    return true;    
}

void Board::display()
{
    for (std::size_t i{0}; i < 4; ++i)
    {
        std::cout<<' ';
        for (std::size_t j{0}; j < 4; ++j)
        {            
            std::cout<<board[i][j];
        }
        std::cout<<'\n';
    }
}

bool Board::move(Direction& dir)
{
    if(emptyTilePos.y+dir.y<0 || emptyTilePos.y+dir.y>=4 || emptyTilePos.x+dir.x<0 || emptyTilePos.x+dir.x>=4) return false;
    std::swap(board[emptyTilePos.y][emptyTilePos.x],board[emptyTilePos.y+dir.y][emptyTilePos.x+dir.x]);
    emptyTilePos.x+=dir.x;
    emptyTilePos.y+=dir.y;
    return true;
}

void Board::randomizeBoard()
{
    int val{Random::get(-1,1)};

    //one component of direction has to be 0
    bool randomBool{static_cast<bool>(Random::get(0,1))};//if randomBool is true, randomDir.y is 0, else randomDir.x is 0

    auto randomDir{Direction{((randomBool)?val:0),((!randomBool)?val:0)}};

    int i{1};
    while (i<=50)
    {
        
        val=Random::get(-1,1);
        randomBool=Random::get(0,1);
        randomDir={Direction{((randomBool)?val:0),((!randomBool)?val:0)}};
        //std::cout<<'('<<((randomBool)?val:0)<<','<<((!randomBool)?val:0)<<")\n";
        if(randomDir.x!=randomDir.y && move(randomDir)) ++i;
    }
}
