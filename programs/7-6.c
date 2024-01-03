#include <stdio.h>

int main() {
    float f1, f2;
    char c;
    int i;

    scanf("%f %d %c %f", &f1, &i, &c, &f2);

    printf("%c %d %.2f %.2f\n", c, i, f1, f2);
}