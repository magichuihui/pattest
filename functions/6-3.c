#include <stdio.h>

#define MAXN 10

int Sum ( int List[], int N );

int main ()
{
    int List[MAXN], N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
int Sum(int List[], int N) {
    int n = MAXN > N ? N : MAXN;
    int total, i;
    for (i=0;i<n;i++) {
        total += List[i];
    }

    return total;
}