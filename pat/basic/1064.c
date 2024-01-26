#include <stdio.h>

int friend(int x);

int main(void) {
    int N;
    int friends[36];
    int i, temp, count=0;
    for (i=0;i<36;i++) friends[i]=0;

    scanf("%d", &N);
    for (i=0;i<N;i++) {
        scanf("%d", &temp);
        if (friends[friend(temp)-1]==0) count++;
        friends[friend(temp)-1]++;
    }

    printf("%d\n", count);
    int first=1;
    for (i=0;i<36;i++) {
        if (friends[i]>0){
            if (!first) printf(" ");
            printf("%d", i+1);
            first=0;
        }
    }
    printf("\n");
}

int friend(int x) {
    int res=0;
    while(x>0) {
        res += x % 10;
        x = x / 10;
    }

    return res;
}