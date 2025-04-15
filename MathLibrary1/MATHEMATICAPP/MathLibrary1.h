#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" {
    MATHLIBRARY_API int Factorial(int n);
    MATHLIBRARY_API double CosTaylor(double x, int n);
    MATHLIBRARY_API double TriangleArea(double a, double b);
}
