#include <stdio.h>

#define MAX_SIZE 100

int gcd(int a, int b);

int main() {
    int N, numerator[MAX_SIZE], denominator[MAX_SIZE];

    scanf("%d\n", &N);

    int i, n, d;
    int temp;
    for (i=0; i<N; i++) {
        scanf("%d/%d", &n, &d);
        temp = gcd(n, d);
        numerator[i] = n / temp;
        denominator[i] = d / temp;
    }

    // 分子 分母
    int gcd_denominator, temp_denominator;
    n=numerator[0];
    d=denominator[0];
    for (i=1; i<N; i++) {
        gcd_denominator = gcd(d, denominator[i]);
        temp_denominator = d * denominator[i] / gcd_denominator;
        n = n * temp_denominator / d + numerator[i] * temp_denominator / denominator[i];
        d = temp_denominator;
        temp = gcd(n, d);
        n = n / temp;
        d = d / temp;
    }

    if (n==0) {
        printf("0\n");
        return 0;
    }

    temp =gcd(n, N);

    n = n / temp;
    d = d * N / temp;

    if (d==1) {
        printf("%d\n", n);
    } else {
        printf("%d/%d\n", n, d);
    }

}

int gcd(int a, int b) {
    if (a<0) a = -1 * a;
    if (b<0) b = -1 * b;
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}