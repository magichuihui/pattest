#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int h=0, t=0, s=0;
    h = n / 100;
    t = (n % 100) / 10;
    s = n % 10;

    int i;
    for(i=0;i<h;i++) {
        printf("B");
    }

    for (i=0;i<t;i++) {
        printf("S");
    }
    for (i=0;i<s;i++) {
        printf("%d", i+1);
    }
}