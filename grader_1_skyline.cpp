#include <stdio.h>
int main() {
	int a, b, c, d, skyline[256];
	for (int i = 0; i < 256; i++) {
		skyline[i] = 0;
	}

	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d %d", &b, &c, &d);
		for (int j = b; j < d; j++) {
			if (skyline[j] < c) {
				skyline[j] = c;
			}
		}
	}
	a = 0;
	for (int i = 0; i < 256; i++) {
		if (a != skyline[i]) {
			a = skyline[i];
			printf("%d %d ", i, a);
		}
	}
}