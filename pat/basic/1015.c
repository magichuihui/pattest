#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 112

typedef struct student {
    int id;
    int virtue;
    int talent;
} student;

typedef struct students {
    student *s[MAX_SIZE];
    int length;
} students;

void insert_sort(students *list, student *s);

int main() {
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);

    students both;
    students virtuous;
    students v2;
    students others;

    both.length=0;
    virtuous.length=0;
    v2.length=0;
    others.length=0;
    
    int i;
    int id, virtue, talent;
    for (i=0;i<N;i++) {
        scanf("%d %d %d", &id, &virtue, &talent);
        student *temp = (student *) malloc(sizeof(student));
        temp->id = id;
        temp->talent = talent;
        temp->virtue = virtue;

        if (virtue >= H && virtue >= L && talent >= H && talent >= L) {
            insert_sort(&both, temp);
        } else if (virtue >= H && virtue >= L && talent >= L && talent < H) {
            insert_sort(&virtuous, temp);
        } else if (virtue >= L && virtue < H && talent >= L && talent < H && virtue >= talent) {
            insert_sort(&v2, temp);
        } else if (virtue >=L && talent >= L) {
            insert_sort(&others, temp);
        }
    }

    printf("%d\n", both.length + virtuous.length + v2.length + others.length);

    for (i=both.length-1;i>=0;i--) {
        printf("%d %d %d\n", both.s[i]->id, both.s[i]->virtue, both.s[i]->talent);
    }

    for (i=virtuous.length-1;i>=0;i--) {
        printf("%d %d %d\n", virtuous.s[i]->id, virtuous.s[i]->virtue, virtuous.s[i]->talent);
    }

    for (i=v2.length-1;i>=0;i--) {
        printf("%d %d %d\n", v2.s[i]->id, v2.s[i]->virtue, v2.s[i]->talent);
    }

    for (i=others.length-1;i>=0;i--) {
        printf("%d %d %d\n", others.s[i]->id, others.s[i]->virtue, others.s[i]->talent);
    }


}

void insert_sort(students *list, student *s) {
    int i = list->length-1;
    int j;
    while(i >= 0 && list->s[i]->talent + list->s[i]->virtue > s->talent + s->virtue) i--;

    // 总分相同
    if (i>=0 && list->s[i]->talent + list->s[i]->virtue == s->talent+s->virtue) {
        // 根据德分降序排列
        while (i>=0 && list->s[i]->talent + list->s[i]->virtue == s->talent+s->virtue && list->s[i]->virtue > s->virtue) i--;
        // 德分也相同
        if (i>=0 && list->s[i]->virtue == s->virtue) {
            while (i>=0 && list->s[i]->talent + list->s[i]->virtue == s->talent+s->virtue && list->s[i]->virtue == s->virtue && list->s[i]->id < s->id) i--;

            for(j=list->length-1;j>i;j--) {
                list->s[j+1] = list->s[j];
            }
            list->s[i+1] = s;
            list->length++;
        } else {
            for(j=list->length-1;j>i;j--) {
                list->s[j+1] = list->s[j];
            }
            list->s[i+1] = s;
            list->length++;
        }
    } else {
        for(j=list->length-1;j>i;j--) {
            list->s[j+1] = list->s[j];
        }
        list->s[i+1] = s;
        list->length++;
    }
}
