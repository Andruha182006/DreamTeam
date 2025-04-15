#pragma once

extern "C" {
    __declspec(dllimport) int Factorial(int n);
    __declspec(dllimport) double CosTaylor(double x, int n);
    __declspec(dllimport) double TriangleArea(double a, double b);
}
