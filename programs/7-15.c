#include <stdio.h>


double f(int n);

int main() {
    double precise;
    scanf("%lf", &precise);

    int i = 0;
    double half_pi=0, fn=f(0);
    while(fn >= precise) {
        half_pi += fn;
        fn = f(++i);
    }
    half_pi += fn;
    printf("%.6lf\n", 2 * half_pi);
}

// 第n项
double f(int n) {
    if(n==0) return 1.0;
    int i;
    double fn=1.0;
    for(i=1;i<=n;i++) {
        fn *= i / (2.0 * i + 1);
    }
    return fn;
}