#ifndef FIGURE_HPP
#define FIGURE_HPP

enum FIGTYPE
{
    RECTANGLE,
    CIRCLE
};

class Figure
{
public:
    int posX, posY;
    int radius = 0, radius_squared = 0, width = 0, height = 0;
    int rotation;
    FIGTYPE type;
    bool check(int, int);

    Figure(int, int, int);
    Figure(int, int, int, int);
};

#endif // FIGURE_HPP