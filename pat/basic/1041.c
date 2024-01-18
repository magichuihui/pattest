#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct student {
    char id[17];
    int trail, real;
} student;

int main() {
    int N;
    scanf("%d", &N);

    student *s[MAX_SIZE];
    int i;
    student *temp;
    for (i=0;i<N;i++) {
         temp = (student *) malloc(sizeof (student));
        scanf("%s %d %d", temp->id, &temp->trail, &temp->real);
        s[temp->trail-1] = temp;
    }

    int query[MAX_SIZE];
    int M;
    scanf("%d", &M);
    for (i=0;i<M;i++) scanf("%d", &query[i]);

    for (i=0;i<M;i++) {
        printf("%s %d\n", s[query[i]-1]->id, s[query[i]-1]->real);
    }
}