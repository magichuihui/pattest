#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

int main(void) {
    char str[MAX_SIZE];

    scanf("%s", str);

    int length = strlen(str);
    int i, t_count=0, p_count=0;
    long res=0;

    for(i=0;i<length;i++) if (str[i]=='T') t_count++;

    for (i=0;i<length;i++) {
        if (str[i] == 'P') {
            p_count++;
        } else if (str[i] == 'A') {
            res += p_count * t_count;
        } else if (str[i] == 'T') {
            t_count--;
        }
    }

    printf("%ld\n", res % 1000000007);
}