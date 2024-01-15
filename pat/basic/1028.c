#include <stdio.h>
#include <string.h>

typedef struct person {
    char name[6];
    int year, month, day;
} person;

typedef struct date {
    int year;
    int month;
    int day;
} date;

int compare(date d1, date d2);
int alive(date d);
int future(date d);


int main(void) {
    int N;

    scanf("%d", &N);

    int i, count=0;
    date max = {10000}, min = {-1}, temp={0};
    char max_name[6], min_name[6];
    char name[6];
    for (i=0;i<N;i++) {
        scanf("%s %d/%d/%d", &name, &temp.year, &temp.month, &temp.day);
        if (!alive(temp) || !future(temp)) continue;
        count++;

        if (compare(max, temp) < 0) {
            max.year=temp.year;
            max.month=temp.month;
            max.day=temp.day;
            strcpy(max_name, name);
            //memcpy(max_name, name, 6);
        }
        if (compare(min, temp) > 0) {
            min.year=temp.year;
            min.month=temp.month;
            min.day=temp.day;
            strcpy(min_name, name);
            //memcpy(min_name, name, 6);
        }

    }

    if (count>0) {
        printf("%d %s %s\n", count, max_name, min_name);
    } else {
        printf("0\n");
    }

}

// 比较出生日期大小
// +    - d1年龄大
// 0    - 相等
// -    - d1 大
int compare(date d1, date d2) {
    if (d1.year!=d2.year) return d2.year-d1.year;

    if (d1.month!=d2.month) return d2.month-d1.month;

    if (d1.day!=d2.day) return d2.day-d1.day;

    return 0;
}

int alive(date d) {
    if (2014-d.year > 200) return 0;
    if (2014-d.year == 200 && d.month < 9) return 0;
    if (2014-d.year == 200 && d.month == 9 && d.day < 6) return 0;

    return 1;
}
int future(date d) {
    if (d.year > 2014) return 0;
    if (d.year==2014 && d.month > 9) return 0;
    if (d.year==2014 && d.month==9 && d.day>6) return 0;

    return 1;
}