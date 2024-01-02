#include <stdio.h>
#include <math.h>

void print_foot_inch(int height);

int main() {
    int height;
    scanf("%d", &height);

    print_foot_inch(height);
    return 0;
}

void print_foot_inch(int height) {
    float f = height / 100.0 / 0.3048;
    float foot = floor(f);
    printf("%.0f %.0f\n", foot, floor((f-foot)*12));
}