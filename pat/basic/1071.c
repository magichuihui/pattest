#include <stdio.h>

int main(void) {
    int T, K;
    scanf("%d %d", &T, &K);

    int i;
    int n1, b, t, n2;
    for (i=0;i<K;i++) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        // 筹码不够
        if (t>T) {
            printf("Not enough tokens.  Total = %d.\n", T);
        } else {
            // 胜
            if (n2>n1 == b) {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            } else {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
                // 输光
                if (T==0) {
                    printf("Game Over.\n");
                    break;
                }
            }
        }

    }
}