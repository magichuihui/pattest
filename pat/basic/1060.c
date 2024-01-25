#include <stdio.h>

// 谁一天骑行140000英里 超人吗
#define MAX_RIDE 140000

int main(void) {
    int N;
    scanf("%d", &N);
    int ride[MAX_RIDE];
    int i, distance;

    for (i=0;i<MAX_RIDE;i++) ride[i]=0;

    for (i=0;i<N;i++) {
        scanf("%d", &distance);
        ride[distance]++;
    }

    for (i=1;i<MAX_RIDE;i++) ride[i] = ride[i]+ride[i-1];

    for (i=0;i<MAX_RIDE;i++) ride[i] = N - ride[i];

    for (i=MAX_RIDE-1;i>=0;i--) {
        if (ride[i]>=i) {
            printf("%d\n", i);
            break;
        }
    }

}