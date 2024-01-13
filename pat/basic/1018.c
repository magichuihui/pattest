#include <stdio.h>

typedef struct counter {
    int C;
    int J;
    int B;
    int win;
    int even;
    int lose;
} counter;

void match(counter *a, counter *b, char mov_a, char mov_b);
char most(counter x);

int main() {
    counter a = {0,0,0,0,0,0};
    counter b = {0,0,0,0,0,0};

    int N;
    scanf("%d\n", &N);

    int i;
    char mov_a, mov_b;
    char mov[5];
    for (i=0;i<N;i++) {
        // scanf("%[A-Z] %[A-Z]", &mov_a, &mov_b);
        fgets(mov, 5, stdin);
        match(&a, &b, mov[0], mov[2]);
    }

    printf("%d %d %d\n", a.win, a.even, a.lose);
    printf("%d %d %d\n", b.win, b.even, b.lose);

    printf("%c %c\n", most(a), most(b));
}

void match(counter *a, counter *b, char mov_a, char mov_b) {
    if (mov_a == 'C') {
        if (mov_b == 'C') {
            a->even++;
            b->even++;
        } else if (mov_b == 'J') {
            a->win++;
            b->lose++;
            a->C++;
        } else if (mov_b == 'B') {
            a->lose++;
            b->win++;
            b->B++;
        }
    } else if (mov_a == 'J') {
        if (mov_b == 'C') {
            a->lose++;
            b->win++;
            b->C++;
        } else if (mov_b == 'J') {
            a->even++;
            b->even++;
        } else if (mov_b == 'B') {
            a->win++;
            b->lose++;
            a->J++;
        }
    } else if (mov_a == 'B') {
        if (mov_b == 'C') {
            a->win++;
            b->lose++;
            a->B++;
        } else if (mov_b == 'J') {
            a->lose++;
            b->win++;
            b->J++;
        } else if (mov_b == 'B') {
            a->even++;
            b->even++;
        }
    }
}

char most(counter x) {
    if (x.B >= x.C) {
        if (x.B >= x.J) return 'B';
    } else {
        if (x.C >= x.J) return 'C';
    }

    return 'J';
}