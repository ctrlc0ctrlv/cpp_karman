#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string>

#define KARMAN_WINFORM
#ifdef KARMAN_WINFORM
#include <windows.h>
#endif

#include <iostream>
#include "karman.h"
using namespace std;

double psi[Q][Q], omega[Q][Q];
double v_x[Q][Q], v_y[Q][Q], v_modul[Q][Q];
double r[Q][Q], e[Q][Q];
double temp[Q][Q], k_next[Q][Q], k1[Q][Q], k2[Q][Q], k3[Q][Q], k4[Q][Q];
double x[Q][Q], y[Q][Q], xp[Q][Q], yp[Q][Q];
unsigned char img[54 + 3 * Q * Q];
double name[Q][Q];

double Re;
double dt = 0.001;
double eps = 0.0001;
double skala = 10.;

int n = 20;
int N = 300 + 1;
int M = 200 + 1;
double a = (double)((double)N / n);
double b = (double)((double)M / n);
double x_k = (a - 1) / 4.;
double y_k = (b - 1) / 2.;
int i_k = (int)(x_k * (double)n + 1);
int j_k = (int)(y_k * (double)n + 1);
double h = (double)1 / n;
int p;
double nu;

// ПАРАМЕТРЫ СРЕДЫ:
double nu_water = 1.006e-3; // кинематическая вязкость воды
double nu_air = 1.51e-2;	// кинематическая вязкость воздуха
double U = Re * nu;			// скорость движения на входе
double T_max = 80. / U;		// характерное время выпуска

int k_max = (int)(round(T_max / dt));
int k = 0;

bool rectangle_check(int i, int j)
{ //проверка: если (i, j)-я ячейка находится внутри обтекаемого квадрата, возвращает 0, если вне - единицу

	if (i_k <= i && i <= i_k + n - 1 && j_k <= j && j <= j_k + n - 1)
		return 0;
	else
		return 1;
}

void hsv_to_rgb(double hue, double sat, double value, double &red, double &green, double &blue)
{ // преобразование цвета HSV в цвет RGB

	double i, f, p, q, t;

	if (value == 0)
	{
		red = 0;
		green = 0;
		blue = 0;
	}
	else
	{
		hue /= 60;
		i = floor(hue);
		f = hue - i;
		p = value * (1 - sat);
		q = value * (1 - (sat * f));
		t = value * (1 - (sat * (1 - f)));
		if (i == 0)
		{
			red = value;
			green = t;
			blue = p;
		}
		else if (i == 1)
		{
			red = q;
			green = value;
			blue = p;
		}
		else if (i == 2)
		{
			red = p;
			green = value;
			blue = t;
		}
		else if (i == 3)
		{
			red = p;
			green = q;
			blue = value;
		}
		else if (i == 4)
		{
			red = t;
			green = p;
			blue = value;
		}
		else if (i == 5)
		{
			red = value;
			green = p;
			blue = q;
		}
	}
}

void initial_conditions_psi()
{
	// начальные и краевые условия для psi(x,y), начальные условия для omega(x,y)
	int i, j;

	// начальные условия psi и omega:
	for (j = 1; j <= M; j++)
		for (i = 1; i <= N; i++)
			psi[i][j] = omega[i][j] = 0;

	// psi граничные условия на верхнем крае:
	for (i = 1; i <= N; i++)
		psi[i][M] = U * b;

	// psi граничные условия на входе и выходе:
	for (j = 1; j <= M; j++)
		psi[1][j] = psi[N][j] = U * b * (double)(j - 1) / (M - 1);

	// обнуление значений внутри квадрата:
	for (j = j_k + 1; j < j_k + n - 1; j++)
		for (i = i_k + 1; i < i_k + n - 1; i++)
			;

	// psi граничные условия на краях квадрата:
	for (i = 0; i < n; i++)
	{
		psi[i_k][j_k + i] = U * b / 2;
		psi[i_k + n - 1][j_k + i] = U * b / 2;
		psi[i_k + i][j_k] = U * b / 2;
		psi[i_k + i][j_k + n - 1] = U * b / 2;
	}
}

void initial_conditions_velocity()
{ //начальные и краевые условия для скорости

	int i, j;

	// скорости на верхнем и нижнем краях области (0, потому что вязкость):
	for (i = 1; i <= N; i++)
		v_x[i][1] = 0,
		v_y[i][1] = 0,
		v_x[i][M] = 0,
		v_y[i][M] = 0;

	// скорости на входе и выходе:
	for (j = 2; j <= M - 1; j++)
		v_x[1][j] = U,
		v_y[1][j] = 0,
		v_x[N][j] = U,
		v_y[N][j] = 0;

	// расчет каждой компоненты (!) скорости через разностную аппроксимацию производной psi:
	for (j = 2; j <= M - 1; j++)
		for (i = 2; i <= N - 1; i++)
			if (rectangle_check(i, j))
				v_x[i][j] = (psi[i][j + 1] - psi[i][j - 1]) / (2 * h),
				v_y[i][j] = -(psi[i + 1][j] - psi[i - 1][j]) / (2 * h);
			else
				v_x[i][j] = 0,
				v_y[i][j] = 0;

	// расчет модуля скорости в каждой точке поля:
	for (j = 1; j <= M; j++)
		for (i = 1; i <= N; i++)
			v_modul[i][j] = sqrt(v_x[i][j] * v_x[i][j] + v_y[i][j] * v_y[i][j]);
}

void draw_color_chart(string s, double pole[Q][Q])
{ // создание и окраска картинок выбранного поля

	int i, j;
	double mn = INF, mx = -INF, MN = INF;
	int x, y;
	int w = N;
	int h = M;

	FILE *f;
	int filesize = 54 + 3 * w * h; // w - ширина изображения, h - высота изображения

	// поиск экстремальных значений поля
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			mn = min(mn, pole[i][j]),
			mx = max(mx, pole[i][j]);
	mn /= skala; // определение границ цветовой шкалы по значениям
	mx /= skala; // изменение этого значения изменяет цветовую шкалу

	double r, g, b, hue; // красный цвет - максимальное значение, фиолетовый цвет - минимальное значение!

	for (j = 1; j <= M; j++)
	{
		for (i = 1; i <= N; i++)
		{
			hue = pole[i][j];
			hue = max(hue, mn);
			hue = min(hue, mx);
			hue = 360 - 360 * (hue - mn) / (mx - mn);
			hue *= 0.8;

			while (hue > 360)
				hue -= 360;
			while (hue < 0)
				hue += 360;

			if (!rectangle_check(i, j))
				hsv_to_rgb(hue, 1, 0, r, g, b);
			else
				hsv_to_rgb(hue, 1, 1, r, g, b);

			r *= 255;
			g *= 255;
			b *= 255;

			x = i - 1;
			y = (h - 1) - j + 1;
			img[(x + y * w) * 3 + 2] = (unsigned char)(r);
			img[(x + y * w) * 3 + 1] = (unsigned char)(g);
			img[(x + y * w) * 3 + 0] = (unsigned char)(b);
		}
	}

	unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
	unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	unsigned char bmppad[3] = {0, 0, 0};

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	f = fopen(s.c_str(), "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (i = 0; i < h; i++)
	{
		fwrite(img + (w * (h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}
	fclose(f);
}

void solve_laplacian_psi(double alfa, double eps)
{ // решение ДУ lap(psi) = - omega
	int i, j, k3;
	double u_p, sum_k, psi_old;
	sum_k = INF;
	k3 = 0;
	while (sum_k > eps)
	{
		sum_k = 0.;
		for (j = 2; j <= M - 1; j++)
		{
			for (i = 2; i <= N - 1; i++)
				if (rectangle_check(i, j))
				{
					u_p = (psi[i - 1][j] + psi[i + 1][j] + psi[i][j - 1] + psi[i][j + 1] + h * h * omega[i][j]) / 4;
					psi_old = psi[i][j];
					psi[i][j] = alfa * psi[i][j] + (1 - alfa) * u_p;
					sum_k += (psi[i][j] - psi_old) * (psi[i][j] - psi_old);
				}
		}
		sum_k = sqrt(sum_k); // точность расчета psi
		k3++;
	}
}

void RK(double k_next[Q][Q], double k4[Q][Q])
{ // схема Рунге-Кутта численного решения ДУ
	int i, j;
	double u_p;
	for (i = 2; i <= N - 1; i++)
		for (j = 2; j <= M - 1; j++)
			if (rectangle_check(i, j))
			{
				u_p = -(psi[i][j + 1] - psi[i][j - 1]) * (k4[i + 1][j] - k4[i - 1][j]) / 4 +
					  (psi[i + 1][j] - psi[i - 1][j]) * (k4[i][j + 1] - k4[i][j - 1]) / 4 +
					  nu * (k4[i + 1][j] + k4[i - 1][j] + k4[i][j + 1] + k4[i][j - 1] - 4 * k4[i][j]);
				k_next[i][j] = dt * u_p / (h * h);
			}
}

void GS(double alfa, int pics_number, int param)
{ // основная часть программы: схема Гаусса-Зейделя
	int i, j;
	double T;
	char str[80];
	for (k = 0, T = 0.; k <= k_max; k++, T += dt)
	{
		// поправки для завихренности (омега) на краях верхней и нижней области:
		for (i = 1; i <= N; i++)
			omega[i][1] = 2 / (h * h) * (psi[i][1] - psi[i][2]),
			omega[i][M] = 2 / (h * h) * (psi[i][M] - psi[i][M - 1]);
		// поправки для завихренности (омега) на входе и выходе:
		for (j = 2; j <= M - 1; j++)
			omega[1][j] = 2 / (h * h) * (psi[1][j] - psi[2][j]),
			omega[N][j] = 2 / (h * h) * (-(psi[N][j]) + psi[N - 1][j]);

		// поправки для завихренности (омега) на границах обтекаемого тела - левой, правой, нижней и верхней соответственно:
		for (i = 0; i < n; i++)
		{
			omega[i_k][j_k + i] = 2 / (h * h) * (psi[i_k][j_k + i] - psi[i_k - 1][j_k + i]);
			omega[i_k + n - 1][j_k + i] = 2 / (h * h) * (psi[i_k + n - 1][j_k + i] - psi[i_k + n][j_k + i]);
			omega[i_k + i][j_k] = 2 / (h * h) * (psi[i_k + i][j_k] - psi[i_k + i][j_k - 1]);
			omega[i_k + i][j_k + n - 1] = 2 / (h * h) * (psi[i_k + i][j_k + n - 1] - psi[i_k + i][j_k + n]);
		}

		RK(k1, omega); // схема Рунге-Кутта численного решения ДУ для омега
		for (i = 2; i <= N - 1; i++)
			for (j = 2; j <= M - 1; j++)
				if (rectangle_check(i, j))
					omega[i][j] += k1[i][j];

		solve_laplacian_psi(alfa, 1e-4); // решение ДУ: laplacian psi = - omega с заданной точностью

		if (k % (k_max / pics_number) == 0 && k != 0)
		{ // первая картинка в нулевой момент времени не сохраняется
			sprintf(str, "animation\\%.3lf.bmp", T);
			initial_conditions_velocity();
			for (int i = 1; i < N; i++)
			{
				for (int j = 1; j < M; j++)
				{ // цикл, выбирающий поле для последующего построения картинок
					switch (param)
					{
					case 0:
						name[i][j] = v_x[i][j];
						break;
					case 1:
						name[i][j] = v_y[i][j];
						break;
					case 2:
						name[i][j] = v_modul[i][j];
						break;
					case 3:
						name[i][j] = omega[i][j];
						break;
					case 4:
						name[i][j] = psi[i][j];
						break;
					default:
						name[i][j] = omega[i][j];
						break;
					}
				}
			}
			draw_color_chart(str, name);
		}
	}
}

void output_to_file(string s, double arr[Q][Q])
{ // вывод в файл значения поля в каждой точке в последний момент времени и параметров моделирования
	int i, j;
	FILE *f = fopen(s.c_str(), "w");
	fprintf(f, "field of length = %d\nfield of width = %d\nRe = %.lf\n", N, M, Re);
	fprintf(f, "spatial accuracy = %.10lf\ntime accuracy = %.10lf\n", eps, dt);
	fprintf(f, "nu = %.5lf\nU = %.5lf\n\n", nu, U);
	// записать в файл:
	for (j = 1; j <= M; j++)
	{
		for (i = 1; i <= N; i++)
		{
			fprintf(f, "%lf ", arr[i][j]);
		}
		fprintf(f, "\n");
		putc(10, f);
	}
	fclose(f);
}

int main(int argc, char argv[])
{
#ifdef KARMAN_WINFORM
	CreateDirectory(TEXT("animation"), NULL);
	initial_conditions_psi();
	if (argc > 1)
	{
		printf("Define path\n");
		int param = atoi(argv);
		GS(-0.5, 200, param);				   //передача в GS-функцию информации о выбранном индексе для режима просмотра
		output_to_file(".\\output.txt", name); //запись в файл
	}
	else
	{
		printf("This path\n");
		GS(-0.5, 200, -1);
		output_to_file(".\\output.txt", omega);
	}
	return 0;
#else
	nu = nu_water;
	Re = 200;
	U = Re * nu;
	T_max = 80. / U;
	// k_max = (int)(round(T_max / dt));
	k_max = 10000;
	initial_conditions_psi();
	printf("This path\n");
	GS(-0.5, 200, -1);
	output_to_file("output.txt", omega);
#endif
}