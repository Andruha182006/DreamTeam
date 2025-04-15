#include "pch.h" // Include the precompiled header file
#include "MathLibrary1.h"
#include <cmath>

// �������� �� ������ �����
int Factorial(int n) {
    if (n < 0) return -1; // �������
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

// ���������� cos(x) ����� ��� �������
double CosTaylor(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        int power = 2 * i;
        double term = pow(-1, i) * pow(x, power) / Factorial(power);
        sum += term;
    }
    return sum;
}

// ����� ������������ ����������
double TriangleArea(double a, double b) {
    return 0.5 * a * b;
}
