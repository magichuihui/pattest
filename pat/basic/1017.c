#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int main() {
    char A[MAX_SIZE];
    int B;
    scanf("%s %d", &A, &B);

    int length = strlen(A);
    
    int i, remainder = 0, q, num;
    for (i=0;i<length;i++) {
        num = A[i] - '0';
        q = (remainder * 10 + num) / B;
        remainder = (remainder * 10 + num) % B;

        if (q==0 && i==0 && length != 1) continue;
        printf("%d", q);
    }

    printf(" %d", remainder);
}