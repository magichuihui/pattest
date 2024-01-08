#include <stdio.h>

#define MAX_SIZE 100000

int main() {
    int a, n;
    scanf("%d %d", &a, &n);

    int result[MAX_SIZE];
    int carry = 0, i, temp;
    for (i=n-1;i>=0;i--) {
        temp = a * (i+1) + carry;
        result[i] = temp % 10;
        carry = temp / 10;
    }

    if (carry > 0) printf("%d", carry);
    for (i=0;i<n;i++) printf("%d", result[i]);

    if (n==0) printf("0");
    printf("\n");

}