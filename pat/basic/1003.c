#include <stdio.h>
#include <string.h>

#define MAX_SIZE 102

int pass(char *str);

int main() {
    int N;
    char answers[MAX_SIZE][10];

    scanf("%d", &N);
    int i;
    for (i=0;i<N;i++) {
        scanf("%s", answers[i]);
    }

    for(i=0;i<N;i++) printf("%s\n", answers[i], pass(answers[i]) ? "YES" : "NO");
}

int pass(char *str) {
    int length = strlen(str);
    int i;

    // P T 的位置
    int p = 0, t = 0;
    for (i=0;i<length;i++) {
        if (str[i] != 'P' && str[i] != 'A' && str[i] != 'T') return 0;
        if (str[i] == 'P') {
            if (p!=0) return 0;
            p = i;
        }
        if (str[i] == 'T') {
            if (t!=0) return 0;
            t = i;
        }
    }

    // P T中间没有字符A  或者T在P前面
    if (t-p < 2) return 0;

    // 对于aPbATca，尾部的A个数要不少于头部
    if (p > length - 1 -t) return 0;

    return 1;
}