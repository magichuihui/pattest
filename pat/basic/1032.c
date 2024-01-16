#include <stdio.h>

#define MAX_SIZE 100000

int main(void) {
    int N;
    scanf("%d", &N);

    int total[MAX_SIZE]={0}, i, id, score;
    for (i=0;i<N;i++) {
        scanf("%d %d", &id, &score);
        if (id>total[0]) total[0]=id;
        total[id] += score;
    }

    int max=total[1];
    id = 1;
    for (i=2;i<=total[0];i++) {
        if (total[i] > max) {
            id = i;
            max = total[i];
        }
    }

    printf("%d %d\n", id, max);

}