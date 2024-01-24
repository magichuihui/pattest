#include <stdio.h>

int main(void) {
    int N;
    int i, sum=0, num;

    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d", &num);
        sum += num;
    }

    printf("%d\n", sum * (N-1) * 11);
}