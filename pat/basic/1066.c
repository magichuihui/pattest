#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M, N;
    int lower, upper, replacement;
    scanf("%d %d %d %d %d", &M, &N, &lower, &upper, &replacement);

    int i, j;
    int **pixel = (int **) malloc(M * sizeof(int *));
    for (i=0;i<M;i++) {
        pixel[i] = (int *) malloc(N * sizeof(int));
        for (j=0;j<N;j++) {
            scanf("%d", &pixel[i][j]);
        }
    }

    for (i=0;i<M;i++) {
        for (j=0;j<N;j++) {
            if (j) printf(" ");
            if (pixel[i][j] <= upper && pixel[i][j] >= lower) {
                printf("%03d", replacement);
            } else {
                printf("%03d", pixel[i][j]);
            }
            
        }
        printf("\n");
    }
}