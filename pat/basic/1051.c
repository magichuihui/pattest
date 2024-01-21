#include <stdio.h>
#include <math.h>

typedef struct complex {
    double real, imaginary;
} complex;

typedef struct complex_polar {
    double R, P;
} complex_polar;

complex product(complex_polar c1, complex_polar c2);

int main(void) {
    complex_polar c1, c2;
    scanf("%lf %lf %lf %lf", &c1.R, &c1.P, &c2.R, &c2.P);

    complex c = product(c1, c2);

    if (c.real < 0 && c.real > -0.005) {
        printf("0.00");
    } else {
        printf("%.2lf", c.real);
    }

    if (c.imaginary < 0 && c.imaginary > -0.005) {
        printf("+0.00i\n");
    } else {
        printf("%+.2lfi\n", c.imaginary);
    }
}

complex product(complex_polar c1, complex_polar c2) {
    complex res;

    res.real = c1.R * c2.R * cos(c1.P+c2.P);
    res.imaginary = c1.R * c2.R * sin(c1.P+c2.P);

    return res;
}