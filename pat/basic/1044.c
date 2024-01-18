#include <stdio.h>
#include <string.h>

void transform(char number[]);
int to_earth(char str[]);

int main(void) {
    int N;
    scanf("%d ", &N);

    int i;
    char temp[100][9];
    for (i=0;i<N;i++) {
        fgets(temp[i], 9, stdin);
        temp[i][strlen(temp[i])-1] = 0;
    }

    for (i=0;i<N;i++) transform(temp[i]);
}

void transform(char number[]) {
    int length = strlen(number);
    char *single[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char *tens[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    int i, num=0;
    // earth
    if (number[0]<='9' && number[0]>='0') {
        for(i=0;i<length;i++) num = number[i]-'0' + num*10;
        // 打印十位的数
        if (num/13 > 0) {
            printf("%s", tens[num/13]);
            if (num % 13 > 0) printf(" %s", single[num%13]);
        } else {
            printf("%s", single[num%13]);
        }
    } else {
        char *token = strtok(number, " ");
        while (token != NULL) {
            num += to_earth(token);
            token = strtok(NULL, " ");
        }
        printf("%d", num);
    }
    printf("\n");
}

int to_earth(char str[]) {
    if (strcmp(str, "tam") == 0) return 13;
    if (strcmp(str, "hel") == 0) return 2*13;
    if (strcmp(str, "maa") == 0) return 3*13;
    if (strcmp(str, "huh") == 0) return 4*13;
    if (strcmp(str, "tou") == 0) return 5*13;
    if (strcmp(str, "kes") == 0) return 6*13;
    if (strcmp(str, "hei") == 0) return 7*13;
    if (strcmp(str, "elo") == 0) return 8*13;
    if (strcmp(str, "syy") == 0) return 9*13;
    if (strcmp(str, "lok") == 0) return 10*13;
    if (strcmp(str, "mer") == 0) return 11*13;
    if (strcmp(str, "jou") == 0) return 12*13;

    if (strcmp(str, "tret") == 0) return 0;
    if (strcmp(str, "jan") == 0) return 1;
    if (strcmp(str, "feb") == 0) return 2;
    if (strcmp(str, "mar") == 0) return 3;
    if (strcmp(str, "apr") == 0) return 4;
    if (strcmp(str, "may") == 0) return 5;
    if (strcmp(str, "jun") == 0) return 6;
    if (strcmp(str, "jly") == 0) return 7;
    if (strcmp(str, "aug") == 0) return 8;
    if (strcmp(str, "sep") == 0) return 9;
    if (strcmp(str, "oct") == 0) return 10;
    if (strcmp(str, "nov") == 0) return 11;
    if (strcmp(str, "dec") == 0) return 12;    
}