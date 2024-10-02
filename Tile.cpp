#include"Tile.h"

int Tile::getValue()
{
    return value;
}

bool Tile::isEmpty()
{
    return !value;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    if(tile.value) out<<tile.value;
    else out<<' ';
    out<<((tile.value/10)?"  ":"   ");
    return out;
}

