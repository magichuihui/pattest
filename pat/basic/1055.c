#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[9];
    int height;
    struct person *next;
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
    // while (p!=NULL) {
    //     printf("%s %d\n", p->name, p->height);
    //     p = p->next;
    // }


    int q = N / K, remainder = N % K, m = q+remainder, mid;
    int j, k, base=0;
    person *res[10000];

    for (i=0;i<K;i++) {
        mid = m/2+1;
        res[base + mid-1] = p;
        p = p->next;
        for (j=1;j<m;j++) {
            // 中间的左边还是右边
            k = j % 2 == 0 ? 1 : -1;
            res[base+mid+k*(j+1)/2-1] = p;
            p=p->next;
        }

        base += m;
        m = q;
    }

    m = q+remainder;
    j = 0;
    for (i=0;i<K;i++) {
        while(m>0) {
            printf("%s", res[j]->name);
            if (m!=1) printf(" ");
            j++;
            m--;
        }
        printf("\n");
        m=q;
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