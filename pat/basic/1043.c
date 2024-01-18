#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10001

int hash(char c);

int main(void) {
    char str[MAX_SIZE];
    scanf("%s", str);

    const char pat[] = {'\n', 'P', 'A', 'T', 'e', 's', 't'};

    int i, counter[7], total=0;
    for (i=0;i<7;i++) counter[i] = 0;

    int length = strlen(str);
    for (i=0;i<length;i++) {
        if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't') {
            counter[hash(str[i])]++;
            total++;
        }
    }

    while(total>0) {
        for (i=1;i<7;i++) if (counter[i]-->0) printf("%c", pat[i]);
        total--;
    }
    printf("\n");
}

int hash(char c) {
    int code=0;
    switch (c) {
    case 'P':
        code = 1;
        break;
    case 'A':
        code = 2;
        break;
    case 'T':
        code = 3;
        break;
    case 'e':
        code = 4;
        break;
    case 's':
        code = 5;
        break;
    case 't':
        code = 6;
        break;
    default:
        break;
    }

    return code;
}