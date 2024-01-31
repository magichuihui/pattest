#include <stdio.h>
#include <math.h>

int prime(int x);

int main(void) {
    int N;
    scanf("%d", &N);

    if (prime(N)) {
        if (N-6>1 && prime(N-6)) {
            printf("Yes\n%d\n", N-6);
            return 0;
        }
        if (prime(N+6)) {
            printf("Yes\n%d\n", N+6);
            return 0;
        }
    }

    int x=N;
    while(1) {
        if (prime(++x)) {
            if ((x-6>1 && prime(x-6)) || prime(x+6)) {
                printf("No\n%d\n", x);
                return 0;
            }
        }
    }
}

int prime(int x) {
    if (x==1) return 0;
    if (x==2) return 1;
    if (x % 2 == 0) return 0;
    int upper = (int) floor(sqrt(x));
    int i;

    for (i=3;i<=upper;i=i+2) if (x % i == 0) return 0;

    return 1;
}