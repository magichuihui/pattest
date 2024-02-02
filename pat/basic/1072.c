#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M, K;
    scanf("%d %d", &N, &M);

    int *forbidden = (int *) malloc(sizeof(int));
    int i;
    for (i=0;i<M;i++) scanf("%d", &forbidden[i]);

    char name[5];
    int j, id, k;
    int counter=0, items=0, first;
    for (i=0;i<N;i++) {
        scanf("%s %d", name, &K);
        first=1;
        for (j=0;j<K;j++) {
            scanf("%d", &id);
            for (k=0;k<M;k++) {
                // 禁止携带
                if (id==forbidden[k]) {
                    if (first) printf("%s:", name);
                    printf(" %04d", id);
                    items++;
                    first=0;
                }
            }
        }

        if (!first) {
            printf("\n");
            counter++;
        }
    }

    printf("%d %d\n", counter, items);
}