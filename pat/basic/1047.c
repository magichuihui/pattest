#include <stdio.h>

#define MAX_SIZE 1000

int main(void) {
    int N, scores[MAX_SIZE];
    scanf("%d", &N);

    int i, team, id, score;
    for (i=0;i<MAX_SIZE;i++) scores[i]=0;

    for (i=0;i<N;i++) {
        scanf("%d-%d %d", &team, &id, &score);
        scores[team] += score;
    }

    id = 1;
    score=scores[1];
    for (i=2;i<MAX_SIZE;i++) {
        if (scores[i]>score) {
            score = scores[i];
            id = i;
        }
    }

    printf("%d %d\n", id, score);

}