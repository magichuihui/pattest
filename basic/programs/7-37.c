#include <stdio.h>

#define MAX_SIZE 30

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int element) {
    // 栈满
    if (s->top > MAX_SIZE - 1) return;
    s->data[s->top++] = element;
}

int pop(Stack *s) {
    // 栈空
    if (s->top == 0) return -1;
    return s->data[s->top--];
}

int empty(Stack *s) {
    return s->top == 0;
}
int full(Stack *s) {
    return s->top > MAX_SIZE - 1;
}

int main() {
    int N;
    scanf("%d", &N);

    Stack s;
    s.top = 0;

    int i, j;
    // 第一个数不能大于N/2
    while (i <= N/2) {

    }
}