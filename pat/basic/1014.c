#include <stdio.h>
#include <string.h>

void day_and_hour(char line1[], char line2[], char *day, char *hour);
char * day_of_week(char day);
int hour_of_day(char hour);
int minute(char line3[], char line4[]);

int main() {
    char cipher[4][61];
    int i;
    for (i=0;i<4;i++) {
        scanf("%s", &cipher[i]);
    }

    char day, hour;
    day_and_hour(cipher[0], cipher[1], &day, &hour);

    printf("%s %02d:%02d\n", day_of_week(day), hour_of_day(hour), minute(cipher[2], cipher[3]));
}

void day_and_hour(char line1[], char line2[], char *day, char *hour) {
    int i = 0;
    while (line1[i] < 'A' || line1[i] > 'G' || line1[i] != line2[i]) {
        i++;
    }
    *day = line1[i++];

    while (((line1[i] < 'A' || line1[i] > 'N') && (line1[i] < '0' || line1[i] > '9')) || line1[i] != line2[i]) i++;

    *hour = line1[i];
}

char * day_of_week(char day) {
    const char* days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    return (char *) days[day - 'A'];
}

int hour_of_day(char hour) {
    if (hour >= '0' && hour <= '9') return hour - '0';
    if (hour >= 'A' && hour <= 'N') return hour - 'A' + 10;
    return 0;
}

int minute(char line3[], char line4[]) {
    int i = 0;
    while(((line3[i] < 'A' || line3[i] > 'Z') && (line3[i] < 'a' || line3[i] > 'z')) || line3[i] != line4[i]) i++;

    return i;
}