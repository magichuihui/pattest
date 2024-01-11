#include <stdio.h>
#include <string.h>

char * day_of_week(char cipher[4][61]);

int main() {
    char cipher[4][61];
    int i;
    for (i=0;i<4;i++) {
        scanf("%s", &cipher[i]);
    }

    printf("%s\n", day_of_week(cipher));
}

char * day_of_week(char cipher[][61]) {
    const char* day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int i=0;
    while (cipher[0][i] < 'A' || cipher[0][i] > 'Z' || cipher[0][i] != cipher[1][i]) i++;

    return (char *) day[cipher[0][i] - 'A'];

}