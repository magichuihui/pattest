#include <stdio.h>

int main() {
    char c;
    int length=0;
    int first=1;
    while(1) {
        scanf("%c", &c);
        if (c==' ') {
            if(length>0) {
                if (!first) {
                    printf(" ");
                } else {
                    first = 0;
                }
                printf("%d", length);
            }
            length = 0;
        } else if (c == '.') {
            if(length>0) {
                if (!first) printf(" ");
                printf("%d\n", length);
            }
            break;
        } else {
            length++;
        }
    }
}