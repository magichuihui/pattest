#include <stdio.h>

#define MAX_SIZE 30

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void Decompose(Stack *s, int N, int remain, int min);
void print_stack(Stack s, int N);

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

int time=0;

int main() {
    int N;
    scanf("%d", &N);

    Stack s;
    s.top = 0;
      

    Decompose(&s, N, N, 1);
}

void print_stack(Stack s, int N) {
    int i;
    printf("%d=", N);
    for (i=0;i<s.top;i++) {
        if (i==0) {
            printf("%d", s.data[i]);
        } else {
            printf("+%d", s.data[i]);
        }
    }
    time++;
    if (time % 4 == 0 || s.data[0] == N) {
        printf("\n");
    } else {
        printf(";");
    }
}

void Decompose(Stack *s, int N, int remain, int min) {
    int i;
    if (remain == 0) {
        print_stack(*s, N);
        return;
    }
    if (min > remain) {
        return;
    }
    for (i=min; i<=remain; i++) {
        push(s, i);
        Decompose(s, N, remain - i, i);
        pop(s);
    }
}
