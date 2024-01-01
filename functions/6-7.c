#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber(const int N) {
    if(pow(floor(sqrt(N)), 2) != N) return 0;

    int a[12];
    int lenth = 0, num, i;
    for  (num = N; num > 0; num = num / 10) {
        a[lenth++] = num % 10;
        for (i=lenth-2;i>=0;i--) {
            if (a[i] == a[lenth-1]) return 1;
        }
    }

    return 0;
}