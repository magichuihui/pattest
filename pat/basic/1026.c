#include <stdio.h>
#include <math.h>

#define CLK_TCK 100

int main(void) {
    int c1, c2;
    scanf("%d %d", &c1, &c2);

    int hour, minute, second;
    int delta = c2 - c1;

    hour = delta / 3600 / CLK_TCK;
    minute = (delta % (3600*CLK_TCK)) / (60 * CLK_TCK);
    second = (int) round((delta % (3600*CLK_TCK)) % (60 * CLK_TCK) * 1.0 / CLK_TCK);

    printf("%02d:%02d:%02d\n", hour, minute, second);
}