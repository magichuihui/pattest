#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    printf("%s\n", a==b ? "C" : (a==c ? "B" : "A"));
}