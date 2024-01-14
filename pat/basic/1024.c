#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int main(void) {
    char number[MAX_SIZE];
    scanf("%s", &number);

    int length = strlen(number);
    
    int start=0,end, sign=1, sign2=1;
    // 底数的符号 跟 起点
    if (number[0] == '+') {
        start=1;
    } else if (number[0] == '-') {
        sign = -1;
        start=1;
        printf("-");
    }

    // 底数终点 后一位的位置
    int i=start;
    while (number[i] != 'E') i++;
    end = i++;

    if (number[i] == '+') {
        sign2 = 1;
        i++;
    } else if (number[i] == '-') {
        sign2 = -1;
        i++;
    }

    // 指数
    int j, exponent=0;
    for (j=i;j<length;j++) {
         exponent = 10 * exponent + (number[j] - '0');
    }

    int decimal=end-start-2;
    // 指数为正
    if (sign2>0) {
        // 指数比小数位数大
        if (exponent >= decimal) {
            for (i=start;i<end;i++) {
                if (i!=start+1) printf("%d",number[i]-'0');
            }
            for (i=0;i<exponent-decimal;i++) printf("0");
        } else {
            for (i=start;i<end;i++) {
                if (i!=start+1) printf("%d", number[i]-'0');
                if (i-start==exponent+1) printf(".");
            }
        }
    // 指数为负
    } else {
        printf("0.");
        for (i=0;i<exponent-1;i++) printf("0");
        for (i=start;i<end;i++) {
            if (i!=start+1) printf("%d", number[i]-'0');
        }
    }
}