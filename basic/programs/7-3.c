#include <stdio.h>

int reverse(int num);

int main() {
    int num;
    scanf("%d", &num);

    printf("%d\n", reverse(num));
}

// 11位以内的整数反转
int reverse(int num) {
    char reverse_num[11];
    int length=0;
    while(num > 0){
        reverse_num[length++] = num % 10;
        num /= 10;
    }

    int i, res = 0;
    for(i=0;i<length;i++) {
        res = res * 10 + reverse_num[i];
    }
    return res;
}