#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500002
int main() {
    char s[MAX_SIZE];
    fgets(s, MAX_SIZE, stdin);

    s[strlen(s)-1] = 0;
    int i=strlen(s)-1, j=0, k;

    int first = 1;
    while(i>=0) {
        if (s[i] != ' ') {
            j++;
        } else {
            // 有单词需要打印
            if (j>0) {
                if (!first) printf(" ");
                for (k=i+1;k<i+j+1;k++) printf("%c", s[k]);
                first = 0;
            }
            j=0;
        }
        i--;
    }

    if(j>0) {
        if (!first) printf(" ");
        for (k=i+1;k<i+j+1;k++) printf("%c", s[k]);
    }
}