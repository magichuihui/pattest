#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int N, M;
    int numbers[MAX_SIZE];

    scanf("%d %d", &N, &M);
    int i;
    for (i=0;i<N;i++) {
        scanf("%d", &numbers[i]);
    }

    int prev_number = numbers[0], temp;
    int id=0, prev, start=0;
    for (i=0; i<N; i++) {
        prev = id;
        id = (id+M) % N;
        temp = numbers[id];
        numbers[id] = prev_number;
        prev_number = temp;

        // 形成循环
        if (id == start) {
            id = id + 1;
            start = id;
            prev_number = numbers[id];
        }
    }

    for (i=0; i<N; i++) {
        printf("%d", numbers[i]);
        if (i<N-1) printf(" ");
    }
}