#include <stdio.h>

int main() {
    int a, b;
    scanf("%d/%d", &a, &b);

    int n = a > b ? b : a;
    int i;
    for(i=n; i>=2; i--) {
        if (a % i == 0 && b % i == 0) {
            a = a / i;
            b = b / i;
        }
    }

    printf("%d/%d\n", a, b);
}