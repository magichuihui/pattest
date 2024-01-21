#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

#define max(a, b) (a) > (b) ? (a) : (b)

char convert(int x);

int main(void) {
    char A[MAX_SIZE], B[MAX_SIZE];
    scanf("%[0-9] %[0-9]", A, B);

    int len_a = strlen(A), len_b = strlen(B);
    int length = max(len_a, len_b);
    char *res = (char *) malloc(length * sizeof(char));
    // 从B的个位到高位（需要考虑A B长度不一致的情况，不足补零）
    int i;
    int temp;
    // 数组A里的数字
    char a, b;
    for (i=1;i<=length;i++) {
        a = i > len_a ? '0' : A[len_a-i];
        b = i > len_b ? '0' : B[len_b-i];
        if (i%2 == 0) {
            temp = b - a;
            if (temp < 0) {
                res[length-i] = '0' + (temp+10);
            } else {
                res[length-i] = '0' + temp;
            }
        } else {
            temp = (b-'0') + (a-'0');
            res[length-i] = convert(temp % 13);
        }
    }
    res[length] = 0;
    printf("%s\n", res);
}

// 将数字转化为模13的字符
char convert(int x) {
    switch (x)
    {
    case 10:
        return 'J';
        break;
    case 11:
        return 'Q';
        break;
    case 12:
        return 'K';
        break;
    default:
        return '0' + x;
        break;
    }   
}