#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int monkeys[MAX_SIZE];
    int N;
    scanf("%d", &N);
    
    int remain=N;
    int i, id=0, counter=0;
    // all moneys have the right to candidacy
    for (i=0;i<N;i++) monkeys[i] = 1;

    while(remain > 1) {
        // the 3rd number
        if (counter == 2) {
            monkeys[id] = 0;
            remain--;
        }

        counter = (counter+1) % 3;
        // find next monkey that has right to candidacy
        id = (id+1)%N;
        while(!monkeys[id]) id = (id+1)%N;
    }

    printf("%d", id+1);
}