#include <stdio.h>
#include <math.h>

// 令漏斗的最大宽度为2k+1, 此时高度h=2k+1
// 此时k: (sqrt(2*N+2)-4)/2 < k <= (sqrt(2*N+2)-2)/2
// k=floor((sqrt(2*N+3)-1)/2)
int main() {
    int N;
    char chr;
    scanf("%d %c", &N, &chr);

    int k = floor((sqrt(2*N+2)-2)/2);

    int i, j;
    for(i=k;i>=0;i--) {
        for(j=0;j<k-i;j++) printf(" ");
        for(j=0;j<2*i+1;j++) printf("%c", chr);
        printf("\n");
    }
    for (i=1;i<=k;i++) {
        for(j=0;j<k-i;j++) printf(" ");
        for(j=0;j<2*i+1;j++) printf("%c", chr);
        printf("\n");
    }

    printf("%d\n", N-2*k*k-4*k-1);
}