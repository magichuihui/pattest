#include <stdio.h>

void transform(unsigned int, unsigned int);

int main() {
    unsigned int A, B, D;
    scanf("%u %u %u", &A, &B, &D);

    transform(A+B, D);
}

void transform(unsigned int n, unsigned int D) {
    if (n==0) {
        printf("0\n");
        return;
    }
    
    if (D==10) {
        printf("%u\n", n);
        return;
    }

    int remainder = n % D;

    if ((n=n/D) !=0) transform(n, D);

    printf("%d", remainder);

}