#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

int calc_m(int N);
int get_index(int m, int n, int x, int y);
int comfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int N;
    scanf("%d", &N);  

    int *numbers = (int *) malloc(N * sizeof(int));
    int i, j;
    for (i=0;i<N;i++) scanf("%d", &numbers[i]); 
    qsort(numbers, N, sizeof(int), comfunc);

    //for (i=0;i<N;i++) printf("%d\n", numbers[i]);

    int m=calc_m(N), n = N/m;
    for (i=1;i<=m;i++) {
        for (j=1;j<=n;j++) {
            printf("%d", numbers[N-get_index(m,n,i,j)]);
            if (j!=n) printf(" ");
        }
        printf("\n");
    }
}

// 计算m n
int calc_m(int N) {
    int m = (int) ceil(sqrt(N));
    int i;
    for (i=m;i<N;i++) if (N%i == 0) break;

    return i;
}

// 计算m x n矩阵元素在数组中的位置
int get_index(int m, int n, int x, int y) {
    // 螺旋矩阵转了i圈，第i圈的行列 (m-2(i-1)) x (n-2(i-1))
    int round = min(min(y-1, n-y), min(x-1, m-x));

    int i, count = 0;
    for (i=round;i>0;i--) {
        count += 2 * (m-2*(i-1) + n-2*(i-1)) - 4;
    }
    
    round++;
    int left=round, right=n-round+1, top=round, bottom=m-round+1;
    int x1 = top, y1 = left;
    // 螺旋的顶部边框
    while(y1 < right) {
        count++;
        if (x1==x && y1==y) return count;
        y1++;
    }
    // 螺旋的右边框
    while(x1 < bottom) {
        count++;
        if (x1==x && y1==y) return count;
        x1++;
    }
    // 底边
    while(y1 > left) {
        count++;
        if (x1==x && y1==y) return count;
        y1--;
    }
    // 左边框
    while(x1 > top) {
        count++;
        if (x1==x && y1==y) return count;
        x1--;
    }
    return count+1;
}