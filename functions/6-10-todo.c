#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial(const int N) {
    if (N < 0 || N > 1000) {
        printf("Invalid input\n");
        return;
    }
    if (N==0 || N==1) {
        printf("1\n");
        return;
    }

    double res=N;
    int n;
    for(n=N-1;n>1;n--) {
        res *= n;
    }
    printf("%Lf\n", res);
}