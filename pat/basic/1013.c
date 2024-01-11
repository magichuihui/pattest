#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int i=2;
    int count=0;
    while (count<N) {
        // 找到素数
        if (is_prime(i)) {
            count++;
            if (count >= M) {
                printf("%d", i);
                if ((count-M) % 10 == 9) {
                    printf("\n");
                } else {
                    if (count < N) printf(" ");
                }
            }
        }
        if (i==2) {i=3;}
        else {i += 2;}
    }
}

int is_prime(int x) {
    if ( x!=2 && x % 2 == 0) return 0;
    double sqrt_of_x = sqrt(x);
    int i;

    for (i=3; i<=sqrt_of_x; i=i+2) {
        if (x % i == 0) return 0;
    }

    return 1;
}