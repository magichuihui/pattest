#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

int main(void) {
    char str[MAX_SIZE];
    int counter_t[MAX_SIZE];
    int counter_p[MAX_SIZE];

    scanf("%s", &str);

    int length = strlen(str);
    int i, t_count=0, p_count=0;
    long long res=0;

    for (i=0;i<length;i++) {
        counter_p[i] = 0;
        counter_t[i] = 0;
    }

    for (i=length-1;i>=0;i--) {
        if (str[i] == 'T') {
            t_count++;
        } else if (str[i] == 'A') {
            counter_t[i] = t_count;
        }
    }
    for (i=0;i<length;i++) {
        if (str[i] == 'P') {
            p_count++;
        } else if (str[i] == 'A') {
            counter_p[i] = p_count;
        }
    }

    for (i=0;i<length;i++) printf("%c %d %d\n", str[i], counter_t[i], counter_p[i]);

    long long res=0;
    for (i=0;i<length;i++) {
        if (str[i] == 'A') {
            res += counter_p[i] * counter_t[i];
        }
    }

    printf("%ld\n", res % 1000000007);


}