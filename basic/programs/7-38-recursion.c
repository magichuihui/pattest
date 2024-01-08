#include <stdio.h>

#define MAX_SIZE 100000

void print_sequence(int a, int n, int level, int carry);

int main() {
    int a, n;
    scanf("%d %d", &a, &n);

    int i, sum=0;

    print_sequence(a, n, n, 0);

    printf("\n");
}

void print_sequence(int a, int n, int level, int carry) {
    if (n==0) printf("0");
    if (level<1) {
        if (carry > 0) printf("%d", carry);
        return;
    }
    int temp = a * level + carry;
    int remainder = temp % 10;
    carry = temp / 10;
    print_sequence(a, n, level-1, carry);

    printf("%d", remainder);
}