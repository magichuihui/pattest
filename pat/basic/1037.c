#include <stdio.h>

typedef struct cash {
    int galleon, sickle, knut;
} cash;

int to_knut(cash);

int main(void) {
    cash P, A;
    scanf("%d.%d.%d %d.%d.%d", &P.galleon, &P.sickle, &P.knut, &A.galleon, &A.sickle, &A.knut);

    int charge = to_knut(A) - to_knut(P);
    if (charge<0) {
        printf("-");
        charge *= -1;
    }
    printf("%d.%d.%d", charge / 17 / 29, (charge / 29) % 17, charge % 29);
}

int to_knut(cash money) {
    return money.galleon * 17 * 29 + money.sickle * 29 + money.knut;
}