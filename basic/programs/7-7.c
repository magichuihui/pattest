#include <stdio.h>

int main() {
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if (hour < 12) {
        printf("%d:%d AM\n", hour, minute);
    } else if (hour > 12) {
        printf("%d:%d PM\n", hour - 12, minute);
    } else {
        printf("%d:%d PM\n", hour, minute);
    }
}