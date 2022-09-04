#include "calculator.hpp"

Calculator::Calculator(int w, int h, ENV env, double reinolds = 200., double deltaT = 1e-3)
{
    width = w;
    height = h;

    psi = std::vector<std::vector<double>>(width);
    omega = std::vector<std::vector<double>>(width);
    for (auto i = 0; i < width; i++)
    {
        psi[i] = std::vector<double>(height, 0);
        omega[i] = std::vector<double>(height, 0);
    }

    switch (env)
    {
    case ENV::AIR:
        nu = NU_AIR;
        break;
    default:
        nu = NU_WATER;
        break;
    }

    re = reinolds;
    vel = re * nu;
    tMax = 80. / vel;
    dt = deltaT;
    maxIter = (int)(tMax / dt);
}

void Calculator::initPsi()
{
    // начальные и краевые условия для psi(x,y), начальные условия для omega(x,y)

    // TODO: replace
    double b = 10.;

    // psi граничные условия на верхнем крае:
    for (auto i = 0; i < width; i++)
        psi[i][height - 1] = vel * b;

    // psi граничные условия на входе и выходе:
    for (auto j = 0; j < height; j++)
        psi[0][j] = psi[width - 1][j] = vel * b * (double)j / height;

    // psi граничные условия на краях квадрата:
    for (auto i = 0; i < n; i++)
    {
        psi[i_k][j_k + i] = vel * b / 2;
        psi[i_k + n - 1][j_k + i] = vel * b / 2;
        psi[i_k + i][j_k] = vel * b / 2;
        psi[i_k + i][j_k + n - 1] = vel * b / 2;
    }
}