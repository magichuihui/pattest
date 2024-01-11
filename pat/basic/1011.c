#include <stdio.h>

int compare(int a, int b, int c);

int main() {
    int T, A[10], B[10], C[10];
    scanf("%d", &T);
    int i;
    for (i=0;i<T;i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
    }

    for (i=0;i<T;i++) {
        printf("Case #%d: %s\n", i+1, compare(A[i], B[i], C[i]) ? "true" : "false");
    }

}

int compare(int a, int b, int c) {
    // a b不同号直接返回 a+b > c
    // 
    if (a>=0) {
        if (b>=0) {
            if (c<0) return 1;
            return a > c - b;
        } else {
            return a+b > c;
        }
    } else {
        if (b>=0) return a+b>c;

        // a<0 b<0
        if (c<0) return a > c-b;
        return 0;
    }
}