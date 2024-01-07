#include <stdio.h>

int main() {
    int numerator1, numerator2, denominator1, denominator2;
    scanf("%d/%d %d/%d", &numerator1, &denominator1, &numerator2, &denominator2);

    int numerator, denominator;
    denominator = lcm(denominator1, denominator2);

    numerator = numerator1 * denominator / denominator1 + numerator2 * denominator / denominator2;

    int gcd1 = gcd(numerator, denominator);
    denominator /= gcd1;
    numerator /= gcd1;

    if (denominator == 1) {
        printf("%d\n", numerator);
    } else {
        printf("%d/%d\n", numerator, denominator);
    }
}

// 求m，n的最大公约数
int gcd(int m, int n) {
    int temp;
    while (n != 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

// 求m, n的最小公倍数
int lcm(int m, int n) {
    return m * n / gcd(m,n);
}