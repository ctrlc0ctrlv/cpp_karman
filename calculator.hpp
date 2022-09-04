#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>

enum ENV
{
    WATER,
    AIR
};

const double NU_WATER = 1.006e-3; // кинематическая вязкость воды
const double NU_AIR = 15.06e-3;   // кинематическая вязкость воздуха

class Calculator
{
private:
    int width, height, maxIter;
    double nu, re, vel, tMax, dt;
    std::vector<std::vector<double>> psi;
    std::vector<std::vector<double>> omega;

public:
    Calculator(int, int, ENV, double, double);
    void initPsi();
    void rungeKutta();
};

#endif // CALCULATOR_HPP