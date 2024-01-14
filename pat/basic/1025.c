#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct Node {
    int data;
    int next;
} Node;

int main(void) {
    int head, N, K;
    scanf("%d %d %d", &head, &N, &K);

    Node *list[MAX_SIZE];

    int i;
    int address, data, next;
    for (i=0;i<N;i++) {
        scanf("%d %d %d", &address, &data, &next);
        Node *n = (Node *) malloc(sizeof(Node *));
        n->data = data;
        n->next = next;
        list[address] = n;
    }

    int current=head, first=head, temp, length=0;

    // 有的节点无用 不在链表里面
    while (current >=0) {
        length++;
        current = list[current]->next;
    }

    current = head;
    int prev = -1;
    int remain = length;
    next = list[current]->next;
    while (remain - K >= 0 && K > 1) {
        for (i=0;i<K-1;i++) {
            temp = list[next]->next;
            list[next]->next = current;
            current = next;
            next=temp;
        }
        // 更改链表头指针
        if (first == head) head = current;
        // 上一段链表的末尾指针
        if (prev != -1) list[prev]->next = current;
        list[first]->next = next;

        current = next;
        if (current != -1 ) next = list[current]->next;

        prev = first;
        first = current;
        remain -= K;
    }

    current = head;
    for (i=0;i<length-1;i++) {
        printf("%05d %d %05d\n", current, list[current]->data, list[current]->next);
        current = list[current]->next;
    }
    printf("%05d %d %d\n", current, list[current]->data, list[current]->next);
}