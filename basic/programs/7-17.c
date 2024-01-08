#include <stdio.h>

int main() {
    int N, U, D;
    scanf("%d %d %d", &N, &U, &D);
    // 是否在向上爬
    int up=1, time=0, move=0;
    while(move < N) {
        time++;
        if(up) {move+=U;}
        else {move-=D;}

        up = !up;
    }

    printf("%d\n", time);
}