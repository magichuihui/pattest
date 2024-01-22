#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

typedef struct symbol_set {
    wchar_t symbols[10][5];
    int length;
} symbol_set;

void generate_set(wchar_t str[], symbol_set *s);

int main(void) {
    wchar_t temp[100];
    symbol_set hands, eyes, mouth;
    setlocale(LC_ALL, "");
    // 手
    fgetws(temp, 100, stdin);
    if (temp[wcslen(temp)-1] == '\n') temp[wcslen(temp)-1]=0;
    generate_set(temp, &hands);

    // 眼
    fgetws(temp, 100, stdin);
    if (temp[wcslen(temp)-1] == '\n') temp[wcslen(temp)-1]=0;
    generate_set(temp, &eyes);

    // 口
    fgetws(temp, 100, stdin);
    if (temp[wcslen(temp)-1] == '\n') temp[wcslen(temp)-1]=0;
    generate_set(temp, &mouth);

    // 继续从标准输入读取一个数字直到换行
    int N;
    fgetws(temp, 10, stdin);


    N = wcstol(temp, NULL, 10);

    // for (i=0;i<hands.length;i++) printf("%ls\n", hands.symbols[i]);

    int i, j, match;
    int *output[5];
    wchar_t * num_end;
    for (i=0;i<N;i++) {
        match=1;
        fgetws(temp, 20, stdin);
        output[i] = (int *) malloc(5 * sizeof(int));

        output[i][0] = wcstol(temp, &num_end, 10);
        output[i][1] = wcstol(num_end, &num_end, 10);
        output[i][2] = wcstol(num_end, &num_end, 10);
        output[i][3] = wcstol(num_end, &num_end, 10);
        output[i][4] = wcstol(num_end, NULL, 10);
    }
    for (i=0;i<N;i++) {
        for (j=0;j<5;j++) {
            // 手
            if (j==0 || j==4) {
                if (output[i][j]<1 || output[i][j]>hands.length) {
                    match=0;
                }
            }
            // 眼
            if (j==1 || j==3) {
                if (output[i][j]<1 || output[i][j]>eyes.length) {
                    match=0;
                }
            }
            if (j==2) {
                if (output[i][j]<1 || output[i][j]>mouth.length) {
                    match=0;
                }
            }
        }

        if (match) {
            printf("%ls", hands.symbols[output[i][0]-1]);
            printf("(");
            printf("%ls", eyes.symbols[output[i][1]-1]);
            printf("%ls", mouth.symbols[output[i][2]-1]);
            printf("%ls", eyes.symbols[output[i][3]-1]);
            printf(")");
            printf("%ls", hands.symbols[output[i][4]-1]);
            printf("\n");
        } else {
            printf("Are you kidding me? @\\/@\n");
        }
    }

}

void generate_set(wchar_t str[], symbol_set *s) {

    int i,j=-1,k=-1;
    s->length=0;

    for (i=0;i<wcslen(str);i++) {
        // 符号集开始
        if (str[i] == '[' && k == -1) {
            j++;
            k=0;
        // 符号集结束
        } else if (str[i] == ']' && k > -1) {
            s->symbols[j][k] = 0;
            s->length++;
            k = -1;
        // 字符属于符号集 j
        } else if (k > -1) {
            s->symbols[j][k++] = str[i];
        }
    }
}