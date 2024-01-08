#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);

    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Median(ElementType A[], int N) {
    int low=0, high=N-1;
    // 用快速排序的思想 寻找中位数
    while(low != high || low != N/2){
        int i=low, j=high;
        ElementType t = A[low];
        while (i<j) {
            // 从后往前找到第一个小于A[low]的元素，移动到A[i]
            while(A[j] > t && i < j) j--;
            if(i<j) A[i++] = A[j];
            while(A[i] < t && i < j) i++;
            if(i<j) A[j--] = A[i];
        }
        A[i] = t;
        // 此时i=j 通过比较i跟N/2 更新low或者high
        if (N-(N+1)/2 == i) return A[i];
        if (N-(N+1)/2 > i) {low=i+1;}
        else {high = i-1;}
    }
    return A[low];
}
