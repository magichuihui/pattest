#include <stdio.h>
#include <math.h>

int main() {
    int N;
    char c;
    scanf("%d %c", &N, &c);

    int i, j;
    for (i=0;i<N;i++) printf("%c", c);
    printf("\n");

    for (i=0;i<round(N/2.0)-2;i++) {
        printf("%c", c);
        for (j=0;j<N-2;j++) printf(" ");
        printf("%c", c);
        printf("\n");
    }

    for (i=0;i<N;i++) printf("%c", c);
    printf("\n");
}