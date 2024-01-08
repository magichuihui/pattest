#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int t=0, running=1, rabbit=0, turtle=0;
    while( 1 ) {
        // rabbit is running
        if(running) {
            if (t+10 >= T) break;

            rabbit += 9 * 10;

            // rabbit is ahead of turtle
            if (rabbit > 3 * t) {
                running = !running;
            }

            t += 10;
        } else {
            if (t+30 >= T) break;

            running = 1;
            t = t + 30;
        }
    }

    turtle = 3 * T;
    // rabbit is running when race is over.
    if (running) rabbit += 9*(T-t);

    if (rabbit > turtle) {
        printf("%s %d\n", "^_^", rabbit);
    } else if (rabbit < turtle) {
        printf("%s %d\n", "@_@", turtle);
    } else {
        printf("%s %d\n", "-_-", turtle);
    }
}
