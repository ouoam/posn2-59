#include <stdio.h>
#include <string.h>

int main() {
    int a = 5, i, j, a2;
    printf("input : ");
    scanf("%d", &a);
    a2 = a * 2;
    for (i = 1; i < a2; i++) {
		for (j = 1; j < a2; j++) {
			if (i < j && a2 - i < j || i > j && a2 - i > j) {
				printf(" ");
			} else {
				printf("%d", j > a ? a2 - j : j);
			}
		}
		printf("\n");
    }
    return 0;
}
