#include <stdio.h>

int str_to_minutes(int time);

int main() {
    int time, delta;
    scanf("%d %d", &time, &delta);

    int minutes_from_0 = str_to_minutes(time) + delta;
    printf("%d%02d", minutes_from_0/60, minutes_from_0%60);

}

int str_to_minutes(int time) {
    return time / 100 * 60 + time % 100;
}