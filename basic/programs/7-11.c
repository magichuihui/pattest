#include <stdio.h>

int main() {
    float consumption, fee;

    scanf("%f", &consumption);

    if (consumption < 15) {
        fee = consumption * 4 / 3;
    } else {
        fee = consumption * 2.5 - 17.5;
    }

    printf("%.2f\n", fee);
}