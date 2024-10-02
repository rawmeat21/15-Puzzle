#include<iostream>

class Tile
{
private:
    int value{};
public:
    Tile(int n=0):value{n}{}

    int getValue();
    bool isEmpty();
    friend std::ostream& operator<<(std::ostream& out,const Tile& tile);
};
