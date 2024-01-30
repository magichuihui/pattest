#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 9973

typedef struct pixel {
    int x, y, color, count;
    struct pixel *next;
} pixel;

int hash(int index);
void insert(pixel *pixels[], int x, int y, int color);
int diff(int **screen, int N, int M, int x, int y, int tol);

int main(void) {
    int M, N, tol;
    scanf("%d %d %d", &M, &N, &tol);

    if (tol < 0) tol = -1 * tol;

    pixel *pixels[MAX_SIZE];

    int **screen = (int **) malloc(N * sizeof(int *));

    int i, j, color;

    for (i=0;i<MAX_SIZE;i++) pixels[i] = NULL;

    for (i=1;i<=N;i++) {
        screen[i] = (int *) malloc(M * sizeof(int));
        for (j=1;j<=M;j++) {
            scanf("%d", &color);
            insert(pixels, i, j, color);
            screen[i][j] = color;
        }
    }

    pixel *head = (pixel *) malloc(sizeof(pixel)), *p=head, *temp;
    int count = 0;
    
    for (i=1;i<MAX_SIZE;i++) {
        temp = pixels[i];
        while (temp) {
            if (temp->count==1) {
                if (diff(screen, N, M, temp->x, temp->y, tol)) {
                    count++;
                    p->next=temp;
                    p=p->next;
                }
            }

            temp = temp->next;
        }
    }

    if (count==1) {
        printf("(%d, %d): %d\n", head->next->y, head->next->x, head->next->color);
    } else if (count==0) {
        printf("Not Exist\n");
    } else {
        printf("Not Unique\n");
    }
 
}

int hash(int index) {
    return index % MAX_SIZE;
}

void insert(pixel *pixels[], int x, int y, int color) {
    int index = hash(color);
    if (pixels[index] == NULL) {
        pixel *p = (pixel *) malloc(sizeof(pixel));
        p->count=1;
        p->x=x;
        p->y=y;
        p->color=color;
        p->next=NULL;
        pixels[index] = p;
    } else {
        pixel *p = pixels[index], *tail;
        // 在pixels查找 
        while (p) {
            if (p->color == color) {
                p->x=x;
                p->y=y;
                p->count++;
                return;
            }
            tail = p;
            p = p->next;
        }

        // 新的颜色值
        p = (pixel *) malloc(sizeof(pixel));
        p->count=1;
        p->x=x;
        p->y=y;
        p->color=color;
        p->next=NULL;
        tail->next = p;
    }
}

// 某像素与周边的颜色差异
int diff(int **screen, int N, int M, int x, int y, int tol) {
    int left = y-1, right = y+1, top = x-1, bottom = x+1;
    // 左上
    if (left > 0 && top > 0 && screen[top][left] <= screen[x][y] + tol && screen[top][left] >= screen[x][y]-tol) return 0;
    // 左中
    if (left > 0 && screen[x][left] <= screen[x][y] + tol && screen[x][left] >= screen[x][y]-tol) return 0;
    // 左下
    if (left > 0 && bottom <= N && screen[bottom][left] <= screen[x][y] + tol && screen[bottom][left] >= screen[x][y]-tol) return 0;
    // 上中
    if (top > 0 && screen[top][y] <= screen[x][y] + tol && screen[top][y] >= screen[x][y]-tol) return 0;
    // 下中
    if (bottom <= N && screen[bottom][y] <= screen[x][y] + tol && screen[bottom][y] >= screen[x][y]-tol) return 0;
    // 右上
    if (top > 0 && right <= M && screen[top][right] <= screen[x][y] + tol && screen[top][right] >= screen[x][y]-tol) return 0;
    // 右中
    if (right <= M && screen[x][right] <= screen[x][y] + tol && screen[x][right] >= screen[x][y]-tol) return 0;
    // 右下
    if (bottom <= N && right <= M && screen[bottom][right] <= screen[x][y] + tol && screen[bottom][right] >= screen[x][y]-tol) return 0;

    return 1;

}