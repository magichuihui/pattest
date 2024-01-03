#include <stdio.h>

int main() {
    int speed;
    char * is_speeding;
    char speeding[] = "Speeding";
    char OK[] = "OK";
    scanf("%d", &speed);

    is_speeding = speed > 60 ? speeding : OK;
    printf("Speed: %d - %s\n", speed, is_speeding);
}