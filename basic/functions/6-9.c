#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit(const int N, const int D) {
    int n, count=0;
    if (N==0 && D == 0) return 1;
    for (n=N>=0?N:-1*N;n!=0;n=n/10) {
        if (n%10 == D) count++;
    }
    return count;
}