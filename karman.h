#ifndef KARMAN
#define KARMAN

#define sign(x) (x < 0 ? -1 : (x == 0 ? 0 : 1))
#define abs(x) (x < 0 ? -(x) : (x))
#define PI 3.14159265358979
#define INF 10000000
#define Q 350 // ������ ��������

int main(int argc, char argv[]);

extern double psi[Q][Q], omega[Q][Q];                                           // ����������� ������� ����
extern double v_x[Q][Q], v_y[Q][Q], v_modul[Q][Q];                              // ���� ���������
extern double r[Q][Q], e[Q][Q];                                                 // ������� ������ � ������ ��� �����
extern double temp[Q][Q], k_next[Q][Q], k1[Q][Q], k2[Q][Q], k3[Q][Q], k4[Q][Q]; // ������� ��� ����� �����-�����
extern double x[Q][Q], y[Q][Q], xp[Q][Q], yp[Q][Q];                             // ������� ��� ��������
extern unsigned char img[54 + 3 * Q * Q];                                       // ������ ��� �������� .bmp �����
extern double name[Q][Q];

extern double Re;    // ����� ���������� �� �����
extern double dt;    // �������� ��������� �������������
extern double eps;   // �������� ���������������� �������������
extern double skala; // ��� ������ �������� "�����", ��� ������� ���������� ���� �����������

extern int n;           // ������� �������� ����������� ������ 1, n - ����� ����� ����� �� ������� ��������
extern int N;           // ���������� ����� ����� � �������������� �����������
extern int M;           // ���������� ����� ����� � ������������ �����������
extern double a;        // ����� �������������� ����
extern double b;        // ������ �������������� ����
extern double x_k, y_k; // ���������� ������ ������� ���� ����������� ��������
extern int i_k, j_k;    // �������, ��������������� ������ ������� ���� ��������
extern double h;        // ��� ����������
extern int p;
extern double nu; // �������������� �������� - ����������� ��������

// ��������� �����:
extern double nu_water; // �������������� �������� ����
extern double nu_air;   // �������������� �������� �������
extern double U;        // �������� ������� �� �����
extern double T_max;    // ����������� ����� �������: ������������ ����� �����
extern int k;           // ������� ����� ��������
extern int k_max;       // ������������ ����� ��������
#endif