#include <stdio.h>
#include <math.h>

int gcd(int, int);
int lcm(int a, int b);

int main(void) {
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    int l = lcm(lcm(m1, m2), k);

    int step = l / k;
    int p1 = n1 * (l/m1), p2 = n2 * (l/m2);

    // whether n1/m1 > n2/m2
    int start = p1 < p2 ? (p1 / step + 1) * step : (p2 / step + 1) * step;
    int end = p1 < p2 ? p2 : p1;

    int i, first=1;
    for (i=start;i<end;i=i+step) {
        if (gcd(i/step, k) < 2) {
            if (!first) printf(" ");
            printf("%d/%d", i/step, k);
            first=0;
        }
    }
    printf("\n");
}

int gcd(int a, int b) {
    int temp;
    while(b!=0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a / g * b;
}