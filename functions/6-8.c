#include <stdio.h>

int Factorial( const int N );
int Factorial2(const int N);

int main()
{
    int N, NF;
    
    scanf("%d", &N);
    NF = Factorial2(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int Factorial(const int N) {
    if (N < 0) return 0;
    if (N == 0) return 1;
    int res = N, i = N;
    while(i>1) {
        res *= --i;
    }
    
    return res;
}

int Factorial2(const int N) {
    if (N<0) return 0;
    if (N==0) return 1;
    return N * Factorial2(N-1);
}