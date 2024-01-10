#include <stdio.h>

#define MAX_SCORE 100
#define MIN_SCORE 0

#define MAX_SIZE 101

int main() {
    char name[MAX_SIZE][11];
    char id[MAX_SIZE][11];
    int score[MAX_SIZE];

    int N;
    scanf("%d", &N);

    int i;
    for (i=0;i<N;i++) {
        scanf("%s %s %d", &name[i], &id[i], &score[i]);
    }

    int min = MAX_SCORE, max = MIN_SCORE;
    int min_id=0, max_id=0;
    for (i=0;i<N;i++) {
        if (min >= score[i]) {
            min = score[i];
            min_id = i;
        }
        if (max <= score[i]) {
            max = score[i];
            max_id = i;
        }
    }

    printf("%s %s\n", name[max_id], id[max_id]);
    printf("%s %s\n", name[min_id], id[min_id]);
}