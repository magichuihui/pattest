#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int main(void) {
    char password[MAX_SIZE];
    int N;
    scanf("%s %d", password, &N);

    char input[MAX_SIZE];
    int retry = 0, finished=0;

    char c;
    while((c=getchar()) != '\n') ;

    while (1) {
        fgets(input, MAX_SIZE, stdin);
        input[strlen(input)-1] = 0;
        if (strlen(input)==0) break;
        if (strcmp(input, "#")==0) break;

        if (!finished) {
            // 密码不匹配
            if (strcmp(input, password) != 0) {
                retry++;
                printf("Wrong password: %s\n", input);
                // 锁定
                if (retry >= N) {
                    printf("Account locked\n");
                    finished=1;
                }
            } else {
                printf("Welcome in\n");
                finished=1;
            }
        }
    }
    return 0;
}