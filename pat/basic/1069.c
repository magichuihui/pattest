#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500

typedef struct person {
    char name[21];
    struct person *next;
} person;

int hash(char *str);
int find(person *winner[], char name[], int index);
void insert(person *winner[], char name[], int index);


int main(void) {
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);

    person *winner[MAX_SIZE];
    int i;
    for (i=0;i<MAX_SIZE;i++) winner[i] = NULL;

    char name[21];
    int index, gap=-1, count=0;
    for (i=1;i<=M;i++) {
        scanf("%s", name);
        index = hash(name);
        // 第一个中奖
        if (i==S) {
            printf("%s\n", name);
            insert(winner, name, index);
            count++;
            gap = 0;
        } else if (gap > -1) {
            gap++;
            if (gap == N) {
                // 第一次中奖
                if (!find(winner, name, index)) {
                    printf("%s\n", name);
                    insert(winner, name, index);
                    count++;
                    gap = 0;
                } else {
                    gap--;
                }
            }
        }
    }

    if (!count) printf("Keep going...\n");
}

int hash(char *str) {
    int length = strlen(str);
    int i;
    int checksum=0;
    for (i=0;i<length;i++) {
        checksum += str[i];
    }

    return checksum % MAX_SIZE;
}

int find(person *winner[], char name[], int index) {
    if (winner[index] == NULL) return 0;
    person *p = winner[index];
    while (p) {
        if (strcmp(p->name, name) == 0) return 1;
        p = p->next;
    }

    return 0;
}

// 获奖人插入哈希表
void insert(person *winner[], char name[], int index) {
    person *temp = (person *) malloc(sizeof(person));
    strcpy(temp->name, name);
    temp->next = NULL;

    if (winner[index] == NULL) {
        winner[index] = temp;
        return;
    }

    person *pre = winner[index];
    while (pre->next) pre = pre->next;

    pre->next = temp;

}