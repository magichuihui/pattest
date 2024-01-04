#include <stdio.h>
#include <string.h>

void print_candle(float open, float close);
void print_shadows(float open, float high, float low, float close);

int main() {
    float open, high, low, close;
    scanf("%f %f %f %f", &open, &high, &low, &close);


    print_candle(open, close);
    print_shadows(open, high, low, close);
}

void print_candle(float open, float close) {
    char solid[] = "BW-Solid";
    char hollow[] = "R-Hollow";
    char cross[] = "R-Cross";

    if (close < open) {
        printf("%s", solid);
    } else if (close > open) {
        printf("%s", hollow);
    } else {
        printf("%s", cross);
    }
}

void print_shadows(float open, float high, float low, float close) {
    if ( low < open && low < close) {
        printf(" with Lower Shadow");
        if (high > open && high > close) {
            printf(" and Upper Shadow");
        }
    } else if (high > open && high > close) {
        printf(" with Upper Shadow");
    }

    printf("\n");
}
