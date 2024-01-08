#include <stdio.h>
#include <math.h>

void print_complex(double real, double imaginary);
void sum(double a1, double b1, double a2, double b2, double *real, double *imaginary);
void difference(double a1, double b1, double a2, double b2, double *real, double *imaginary);
void product(double a1, double b1, double a2, double b2, double *real, double *imaginary);
void quotient(double a1, double b1, double a2, double b2, double *real, double *imaginary);

void print_equation(double a1, double b1, double a2, double b2, char op);

int main() {
    double a1, b1, a2, b2;
    scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);

    print_equation(a1, b1, a2, b2, '+');
    print_equation(a1, b1, a2, b2, '-');
    print_equation(a1, b1, a2, b2, '*');
    print_equation(a1, b1, a2, b2, '/');
}

void print_complex(double real, double imaginary) {
    real = round(real * 10) / 10;
    imaginary = round(imaginary * 10) / 10.0;
    if (real == 0.0 && imaginary == 0.0) {
        printf("0.0");
    } else if (real == 0.0) {
        printf("%.1lfi", imaginary);
    } else if (imaginary == 0.0) {
        printf("%.1lf", real);
    } else {
        printf("%.1lf%+.1lfi", real, imaginary);
    }
}

void print_operand(double real, double imaginary) {
    real = round(real * 10) / 10;
    imaginary = round(imaginary * 10) / 10.0;

    printf("%.1lf%+.1lfi", real, imaginary);
}

void print_equation(double a1, double b1, double a2, double b2, char op) {
    double real, imaginary;

    if (op == '+') {
        sum(a1, b1, a2, b2, &real, &imaginary);
    } else if (op == '-') {
        difference(a1, b1, a2, b2, &real, &imaginary);
    } else if (op == '*') {
        product(a1, b1, a2, b2, &real, &imaginary);
    } else if (op == '/') {
        quotient(a1, b1, a2, b2, &real, &imaginary);
    }

    printf("(");
    print_operand(a1, b1);
    printf(") %c (", op);
    print_operand(a2, b2);
    printf(") = ");
    print_complex(real, imaginary);
    printf("\n");
}

void sum(double a1, double b1, double a2, double b2, double *real, double *imaginary) {
    *real = a1 + a2;
    *imaginary = b1 + b2;
}

void difference(double a1, double b1, double a2, double b2, double *real, double *imaginary) {
    *real = a1 - a2;
    *imaginary = b1 - b2;
}

void product(double a1, double b1, double a2, double b2, double *real, double *imaginary) {
    *real = a1 * a2 - b1 * b2;
    *imaginary = a1 * b2 + a2 * b1;
}

void quotient(double a1, double b1, double a2, double b2, double *real, double *imaginary) {
    *real = (a1*a2+b1*b2) / (a2*a2 + b2*b2);
    *imaginary= (b1*a2 - a1*b2) / (a2*a2 + b2*b2);
}