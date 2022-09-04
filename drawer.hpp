#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <vector>
#include <array>
#include <string>
#include "figure.hpp"

class Drawer
{
private:
    unsigned int width, height;
    const int INF = 10000000;
    const double skala = 10.;
    bool gridUpdated;
    std::vector<Figure *> figures;
    std::vector<std::vector<double>> pole;
    std::vector<std::vector<int>> grid;

public:
    Drawer(int, int);
    ~Drawer();
    void updateGrid();
    void drawArr();
    void drawBMP(std::string);
    void addFig(Figure *);
};

///////////////////////////////////////////////////////////////////////////////

class HSV
{
public:
    double hue, sat, value;
    HSV(double, double, double);
    std::array<double, 3> asRGB();
};

#endif // DRAWER_HPP
