#ifndef KARMAN
#define KARMAN

#define sign(x) (x < 0 ? -1 : (x == 0 ? 0 : 1))
#define abs(x) (x < 0 ? -(x) : (x))
#define PI 3.14159265358979
#define INF 10000000
#define Q 350 // размер массивов

int main(int argc, char argv[]);

extern double psi[Q][Q], omega[Q][Q];                                           // неизвестные функции пол€
extern double v_x[Q][Q], v_y[Q][Q], v_modul[Q][Q];                              // пол€ скоростей
extern double r[Q][Q], e[Q][Q];                                                 // векторы ошибок и базисы дл€ сетки
extern double temp[Q][Q], k_next[Q][Q], k1[Q][Q], k2[Q][Q], k3[Q][Q], k4[Q][Q]; // функции дл€ схемы –унге- утта
extern double x[Q][Q], y[Q][Q], xp[Q][Q], yp[Q][Q];                             // функции дл€ анимации
extern unsigned char img[54 + 3 * Q * Q];                                       // массив дл€ создани€ .bmp файла
extern double name[Q][Q];

extern double Re;    // число –ейнольдса на входе
extern double dt;    // точность временной дискретизации
extern double eps;   // точность пространственной дискретизации
extern double skala; // чем больше значение "шкалы", тем сильнее измен€етс€ цвет изображени€

extern int n;           // сторона квадрата принимаетс€ равной 1, n - число €чеек сетки на сторону квадрата
extern int N;           // количество €чеек сетки в горизонтальном направлении
extern int M;           // количество €чеек сетки в вертикальном направлении
extern double a;        // длина пр€моугольного пол€
extern double b;        // ширина пр€моугольного пол€
extern double x_k, y_k; // координаты левого нижнего угла обтекаемого квадрата
extern int i_k, j_k;    // индексы, соответствующие левому нижнему углу квадрата
extern double h;        // шаг рассто€ни€
extern int p;
extern double nu; // кинематическа€ в€зкость - абстрактный параметр

// ѕј–јћ≈“–џ —–≈ƒџ:
extern double nu_water; // кинематическа€ в€зкость воды
extern double nu_air;   // кинематическа€ в€зкость воздуха
extern double U;        // скорость течени€ на входе
extern double T_max;    // характерное врем€ выпуска: максимальное врем€ счета
extern int k;           // счетчик числа итераций
extern int k_max;       // максимальное число итераций
#endif