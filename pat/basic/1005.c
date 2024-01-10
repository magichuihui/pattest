#include <stdio.h>

int callatz(int *times, int n);

int main () {
    int K;
    scanf("%d", &K);
    int i, numbers[101];
    // 记录数字n在运算中出现过几次
    int times[101];
    for (i=2; i<101;i++) {
        times[i] = 0;
        numbers[i] = 0;
    }
    int temp;
    for (i=0;i<K;i++) {
        scanf("%d", &temp);
        numbers[temp] = 1;
    }



    for (i=2;i<101;i++) {
        if (numbers[i]) callatz(times, i);
    }

    int first=1;
    for (i=100; i>1; i--) {
        if (numbers[i] == 1) {
            if (times[i] == 1) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
    }
    printf("\n");
}

int callatz(int *times, int n) {
    if (n == 1) return 0;
    if (n<101 && n >=2) times[n]++;
    if (n%2 == 0) return callatz(times, n/2);
    return callatz(times, (3 * n + 1) / 2);
}