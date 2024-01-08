#include <stdio.h>

// BCD码
int main() {
    int num;
    scanf("%d", &num);

    // 把num转换成16进制，然后当作十进制输出
    printf("%d\n", num/16*10 + (num%16) );   
}