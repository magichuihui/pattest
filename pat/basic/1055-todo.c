#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[9];
    int height;
    person *next;
} person;

void insert(person *p, char *name, int height);

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int i;
    person *p;
    person *list[271];
    for (i=0;i<271;i++) {
        p = (person *) malloc(sizeof(person));
        p->next = NULL;
        list[i] = p;
    }
    char name[9];
    int height;
    for(i=0;i<N;i++) {
        scanf("%s %d", name, &height);
        insert(list[height-30], name, height);
    }

    i=270;
    person *head = (person *) malloc(sizeof(person));
    head->next=NULL;
    person *current = head->next;
    while (i>=0) {
        if (list[i]->next != NULL) {
            // 第一次找到最高的人
            if (current==NULL) {
                head->next = list[i]->next;
                current = list[i]->next;
            } else {
                current->next = list[i]->next;
                current = current->next;
            }

            while (current->next!=NULL) current = current->next;
            i--;
        } else {
            i--;
        }
    }

    p = head->next;
    while (p!=NULL) {
        printf("%s %d\n", p->name, p->height);
        p = p->next;
    }
}

void insert(person *p, char *name, int height) {
    person *pre = p;
    person *current = p->next;
    while(current != NULL) {
        if (strcmp(current->name, name) > 0) break;

        pre = current;
        current = current->next;
    }

    person *temp = (person *) malloc(sizeof(person));
    temp->height = height;
    strcpy(temp->name, name);
    temp->next = current;
    pre->next = temp;
}