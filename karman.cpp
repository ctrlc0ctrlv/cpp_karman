#include <iostream>
#include "karman.hpp"
#include "figure.hpp"
#include "drawer.hpp"

Karman::Karman(/* args */)
{
}

Karman::~Karman()
{
}

int main()
{
    int w = 300;
    int h = 200;
    Drawer d(w, h);
    Figure *rec = new Figure(1, 1, 3, 5);
    d.addFig(rec);
    Figure *circ = new Figure(100, 50, 50);
    d.addFig(circ);
    // d.drawArr();
    d.drawBMP("out.bmp");
    std::cout << "Done" << std::endl;
}
