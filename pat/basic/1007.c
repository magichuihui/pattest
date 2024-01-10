#include <stdio.h>
#include <math.h>

int is_prime(int number);

int main(void) {
    int N;
    scanf("%d", &N);

    int i;
    int count=0;
    for(i=2;i<=N-2;i++) {
        if (is_prime(i)) {
            if (is_prime(i+2)) count++;
        }
    }

    printf("%d", count);

}

int is_prime(int number) {
    int i;
    for (i=2;i<=sqrt(number);i++) {
        if (number % i == 0) return 0;
    }

    return 1;
}