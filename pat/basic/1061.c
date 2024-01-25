#include <stdio.h>
#include <stdlib.h>

typedef struct question {
    int score, answer;
} question;

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    question **questions = (question **) malloc(M * sizeof(question *));
    int i, j;
    for (i=0;i<M;i++) {
        questions[i] = (question *) malloc(sizeof(question));
        scanf("%d", &questions[i]->score);
    }
    for (i=0;i<M;i++) {
        scanf("%d", &questions[i]->answer);
    }

    int answer;
    int *total = (int *) malloc(N * sizeof(int));
    for (i=0;i<N;i++) {
        total[i]=0;
        for (j=0;j<M;j++) {
            scanf("%d", &answer);
            if (answer==questions[j]->answer) total[i] += questions[j]->score;
        }
    }

    for (i=0;i<N;i++) printf("%d\n", total[i]);
}