#include <stdio.h>
#include <string.h>

#define MAX_SIZE 82

int main() {
    char words[MAX_SIZE];
    fgets(words, MAX_SIZE, stdin);

    int length = strlen(words);
    words[length-1] = 0;

    // i - 字符数组的id， j - 单词的长度
    int i, j=0, k;
    // 最后一个单词
    int last = 1;
    for (i=length-2;i>=0;i--) {
        // 遇到空字符
        if (words[i] == ' ') {
            // i位于单词起始位置
            if (j!=0) {
                if (!last) printf(" ");
                for(k=i+1;k<i+1+j;k++) {
                    printf("%c", words[k]);
                }
                last = 0;
            }
            j=0;
        } else {
            j++;
        }
    }

    // j > 0
    if (j>0) {
        if (!last) printf(" ");
        for(k=i+1;k<i+1+j;k++) {
            printf("%c", words[k]);
        }
    }
}