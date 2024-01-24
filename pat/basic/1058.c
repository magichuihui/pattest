#include <stdio.h>
#include <stdlib.h>

typedef struct question {
    int score, correct, wrong;
} question;

int hash(char opt);

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int i, j;
    int score, c_option, c_correct;
    char opt;
    question **questions = (question **) malloc(M * sizeof(question *));

    for (i=0;i<M;i++) {
        scanf("%d %d %d", &score, &c_option, &c_correct);
        questions[i] = (question *) malloc(sizeof(question));
        questions[i]->score = score;
        questions[i]->correct = 0;
        questions[i]->wrong = 0;

        for (j=0;j<c_correct;j++) {
            scanf(" %c", &opt);
            questions[i]->correct |= hash(opt);
        }
    }

    while (getchar() != '\n');

    i=0;
    int *scores = (int *) malloc(N* sizeof(int));
    for (i=0;i<N;i++) scores[i] = 0;
    char c;
    for (i=0;i<N;i++) {
        j = -1;
        while((c=getchar()) != '\n') {
            if (c=='(') {
                j++;
                score=0;
            }
            if (c<='e' && c>='a') {
                score |= hash(c);
            }
            if (c==')') {
                // 回答正确
                if (score == questions[j]->correct) {
                    scores[i] += questions[j]->score;
                } else {
                    questions[j]->wrong++;
                }
            }
        }
    }

    for (i=0;i<N;i++) printf("%d\n", scores[i]);

    int max=0;
    for (i=0;i<M;i++) if (questions[i]->wrong>max) max=questions[i]->wrong;

    if (max==0) {
        printf("Too simple\n");
    } else {
        printf("%d", max);
        for (i=0;i<M;i++) if (questions[i]->wrong == max) printf(" %d", i+1);
        printf("\n");
    }
    
}

// 把选项转化成数字
// a - 1
// b - 2
// c - 4
// d - 8
// e - 16
int hash(char opt) {
    switch (opt)
    {
    case 'a':
        return 1;
        break;
    case 'b':
        return 2;
        break;
    case 'c':
        return 4;
        break;
    case 'd':
        return 8;
        break;
    case 'e':
        return 16;
        break;
    default:
        return 0;
        break;
    }
}