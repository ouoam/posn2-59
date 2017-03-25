#include <stdio.h>

int m, n, t;
int street[102][42];

bool find(int Tn, int Tt) {
	if (Tn < 1 || Tn > m || street[Tt][Tn] == 1) {
		return false;
	}
	if (Tt >= t) {
		return true;
	}
	if (find(Tn, Tt + 1)) {
		street[Tt][0] = 3;
	} else if (find(Tn - 1, Tt + 1)) {
		street[Tt][0] = 1;
	} else if (find(Tn + 1, Tt + 1)) {
		street[Tt][0] = 2;
	} else {
		return false;
	}
	return true;
}

int main() {
	scanf("%d %d %d", &m, &n, &t);
	for (int i = 1; i <= m; i++) {
		street[0][i] = 0;
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &street[i][j]);
		}
	}
	find(n, 0);
	for (int i = 0; i < t; i++) {
		printf("%d\n", street[i][0]);
	}
}
