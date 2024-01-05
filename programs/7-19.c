#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int f, y;
    // 100f + y - n = 200y + 2f => 98f - n = 199y
    for(f=1;f<100;f++) {
        if(98 * f - n >= 0 ) {
            if ((98 * f - n) % 199 ==0) {
                y = (98 * f - n) / 199;
                printf("%d.%d", y, f);
                return 0;
            }
        }
    }

    printf("No Solution\n");
}