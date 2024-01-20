#include <stdio.h>
#include <stdlib.h>

typedef struct match {
    int call1, action1, call2, action2;
} match;

int lose(match m);

int main(void) {
    int N;
    scanf("%d", &N);

    match *matches = (match *) malloc(N * sizeof(match));
    int i;
    for (i=0;i<N;i++) scanf("%d %d %d %d", &matches[i].call1, &matches[i].action1, &matches[i].call2, &matches[i].action2);

    int drink[3] = {0, 0, 0};

    for (i=0;i<N;i++) {
        drink[lose(matches[i])]++;
    }

    printf("%d %d\n", drink[0], drink[1]);
}

// 比赛中的输家
// 0 - 甲输
// 1 - 乙输
// 2 - 都赢或都输
int lose(match m) {
    int call = m.call1 + m.call2;
    // 乙输
    if (call == m.action1 && call != m.action2) return 1;
    // 甲输
    if (call != m.action1 && call == m.action2) return 0;

    return 2;
}