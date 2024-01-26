#include <stdio.h>
#include <math.h>

int main(void) {
    int N;
    int i, real, imaginary;

    double max=0, temp;

    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d %d", &real, &imaginary);
        temp = sqrt(real*real + imaginary*imaginary);
        max = max>temp ? max : temp;
    }

    printf("%.2lf\n", max);
}