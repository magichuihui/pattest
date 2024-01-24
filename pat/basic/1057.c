#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100002

int main(void) {
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);

    str[strlen(str)-1]=0;

    int i, sum=0;
    for (i=0;i<strlen(str);i++) {
        if (str[i]>='a' && str[i]<='z') {
            sum += str[i] - 'a' + 1;
        } else if (str[i]>='A' && str[i] <= 'Z') {
            sum += str[i] - 'A' + 1;
        }
    }

    if (sum==0) {
        printf("0 0\n");
        return 0;
    }

    int count[]= {0,0};
    while (sum>0) {
        count[sum%2]++;
        sum = sum/2;
    }

    printf("%d %d\n", count[0], count[1]);
}