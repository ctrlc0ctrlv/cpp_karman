#include <algorithm>
#include "figure.hpp"

Figure::Figure(int x, int y, int r)
{
    posX = x;
    posY = y;
    radius = r;
    radius_squared = pow(r, 2);
    type = FIGTYPE::CIRCLE;
}

Figure::Figure(int x, int y, int w, int h)
{
    posX = x;
    posY = y;
    width = w;
    height = h;
    type = FIGTYPE::RECTANGLE;
}

bool Figure::check(int x, int y)
{
    int centX = posX + radius;
    int centY = posY + radius;
    switch (type)
    {
    case FIGTYPE::CIRCLE:
        if (pow(centX - x, 2) + pow(centY - y, 2) < radius_squared)
            return true;
        return false;
    default:
        if ((posX <= x) && (x < posX + width) && (posY <= y) && (y < posY + height))
            return true;
        return false;
    }
}