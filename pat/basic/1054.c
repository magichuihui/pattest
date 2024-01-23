#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid(char *number);

int main(void) {
    int N;
    scanf("%d", &N);
    
    char **numbers = (char **) malloc(N * sizeof(char *));

    int i;
    for (i=0;i<N;i++) {
        numbers[i] = (char *) malloc(20 * sizeof(char));
        scanf("%s", numbers[i]);
    }

    double temp, sum=0;
    int count = 0, last;
    for (i=0;i<N;i++) {
        if (valid(numbers[i])) {
            temp = atof(numbers[i]);
            if (temp > 1000 || temp < -1000) {
                printf("ERROR: %s is not a legal number\n", numbers[i]);
            } else {
                count++;
                sum += temp;
                last = i;
            }
        } else {
            printf("ERROR: %s is not a legal number\n", numbers[i]);
        }
    }
    if (count==0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (count==1) {
        printf("The average of 1 number is %.2lf\n", sum);
    } else {
        printf("The average of %d numbers is %.2lf\n", count, sum/count);
    }
}

int valid(char *number) {
    int i, len = strlen(number);
    int pos = -1;
    for (i=0;i<len;i++) {
        if ((number[i]<'0' || number[i]>'9') && number[i] != '-' && number[i] != '+' && number[i] != '.' ) return 0;
        // 符号不再第一位
        if ((number[i] == '-' || number[i] == '+') && i !=0 ) return 0;

        // 小数
        if (number[i] == '.') {
            if (i==0) return 0;
            // 第二个小数点
            if (pos>0) {
                return 0;
            } else {
                pos = i;
            }
        }
    }
    
    if (pos > 0) return len - 1 - pos <= 2;
    return 1;
}