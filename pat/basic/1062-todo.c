#include <stdio.h>
#include <math.h>

long long gcd(long long, long long);
long long lcm(long long a, long long b);

int main(void) {
    long long n1, m1, n2, m2, k;
    scanf("%lld/%lld %lld/%lld %lld", &n1, &m1, &n2, &m2, &k);

    long long l = lcm(lcm(m1, m2), k);

    long long step = l / k;
    long long start = (n1 * (l/m1) / step + 1) * step, end = n2 * (l/m2);

    long long i, first=1;
    for (i=start;i<end;i=i+step) {
        if (gcd(i/step, k) < 2) {
            if (!first) printf(" ");
            printf("%lld/%lld", i/step, k);
            first=0;
        }
    }
    printf("\n");
}

long long gcd(long long a, long long b) {
    long long temp;
    while(b!=0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    return a / g * b;
}