#include <stdio.h>

int pa(int a, int d);

int main() {
    int a, da, b, db;
    scanf("%d %d %d %d", &a, &da, &b, &db);

    printf("%d\n", pa(a, da) + pa(b, db));

}

int pa(int a, int d) {
    if (d==0) return 0;

    int res=0, remainder;
    while (a>0) {
        remainder = a % 10;
        if (remainder == d) res = res * 10 + d;
        a /= 10;
    }

    return res;
}
