#include"Board.h"
#include<iostream>
#include<cstdlib>
#include<limits>

class Player
{
    char moveInput{};
public:
    Direction getDirection();
};

Direction Player::getDirection()
{

    std::cout<<"\nEnter your move: ";
    std::cin>>moveInput;

    switch (moveInput)
    {
    case 'w':
        return {0,1};
        break;
    case 's':
        return {0,-1};
        break;
    case 'a':
        return {1,0};
        break;
    case 'd':
        return {-1,0};
        break;
    case 'q':
        std::cout<<"\nNOOB\n\n";
        std::exit(0);
    default:
        return {0,0};
        break;
    }
}

bool loadGame()
{
    char c{};
    std::cout<<"Enter any key to load a new game(press 'q' to exit): ";
    std::cin>>c;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if(c=='q') return false;
    return true;
}

int main()
{
    Board board{};
    Player player;

    board.display();

    if(!loadGame()) 
    {
        std::cout<<"\nPUSSY\n\n";
        return 0;
    }

    board.randomizeBoard();

    board.display();

    Direction dir{};
    while (true)
    {
        dir=player.getDirection();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        board.move(dir);

        board.display();

        if(board.checkWinCondition())
        {
            std::cout<<"\nYou won!\n\n";
            return 0;
        }
    }
}
