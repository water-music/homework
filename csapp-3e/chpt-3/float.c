/* gcc -Og -S float.c */
#include <complex.h>

typedef enum
{
    NEG,
    ZERO,
    POS,
    OTHER
} range_t;

range_t find_range(float x)
{
    int result;
    if (x < 0)
    {
        result = NEG;
    }
    else if (x == 0)
    {
        result = ZERO;
    }
    else if (x > 0)
    {
        result = POS;
    }
    else
    {
        result = OTHER;
    }
    return result;
}

double c_imag(double complex x)
{
    return cimag(x);
}

double c_real(double complex x)
{
    return creal(x);
}

double complex c_sub(double complex x, double complex y)
{
    return x - y;
}