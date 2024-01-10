#include <stdio.h>

#define MAX_SIZE 2000

int main() {
    int numbers[MAX_SIZE];

    int count = 0;
 
    // Perform a do-while loop
    do {
        scanf("%d", &numbers[count++]);
    } while (getchar() != '\n' && count < 2000);

    int i;
    for (i=0;i<count;i++) printf("%d\n", numbers[i]);

    
}