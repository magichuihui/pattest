#include <stdio.h>

int calltz(int n);

int main() {   
    int n;
    scanf("%d", &n);
    int x = calltz(n);
    printf("times of calltz %d: %d", 100, x);
}

int calltz(int n) {
    if (n==1) return 0;
    if (n % 2 == 0) return 1 + calltz(n/2);
    return 1 + calltz((3*n+1)/ 2);
}