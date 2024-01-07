#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
    char name[11];
    char date[11];
    char gender;
    char landline[17];
    char mobile[17];
} person;

int main() {
    int N;
    scanf("%d\n", &N);

    struct person p1[10];
    int i;
    for (i=0; i<N; i++) {
        scanf("%s %s %c %s %s\n", &p1[i].name, &p1[i].date, &p1[i].gender, &p1[i].landline, &p1[i].mobile);
    }

    char id_list[30];
    int ids[11];
    fgets(id_list, 30, stdin);
    id_list[strlen(id_list)-1] = 0;

    char *token;
    token = strtok(id_list, " ");
    int count=0;
    while (token != NULL) {
        ids[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int print_count = ids[0];
    for (i=1; i<= print_count; i++) {
        if (ids[i] >=0 && ids[i] < N) {
            printf("%s %s %s %c %s\n", p1[ids[i]].name, p1[ids[i]].landline, p1[ids[i]].mobile, p1[ids[i]].gender, p1[ids[i]].date);
        } else {
            printf("Not Found\n");
        }
    }

   return 0;
}