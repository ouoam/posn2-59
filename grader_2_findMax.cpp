#include <stdio.h>

int map[22][22], n;
bool check[22][22];

inline int max(int a, int b) { return a > b ? a : b; }

int walk(int a, int b) {
	if (a < 0 || b < 0 || a == n || b == n) {
		return 0;
	}
	check[a][b] = true;
	int ma = map[a][b];

	if (map[a + 1][b] > ma && check[a + 1][b] == false) {
		ma = max(ma, walk(a + 1, b));
	}
	if (map[a][b + 1] > ma && check[a][b + 1] == false) {
		ma = max(ma, walk(a, b + 1));
	}
	if (map[a - 1][b] > ma && check[a - 1][b] == false) {
		ma = max(ma, walk(a - 1, b));
	}
	if (map[a][b - 1] > ma && check[a][b - 1] == false) {
		ma = max(ma, walk(a, b - 1));
	}

	check[a][b] = false;
	return ma;
}

int main() {
	int sa, sb;
	scanf("%d", &n);
	scanf("%d %d", &sa, &sb);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 100) {
				check[i][j] = true;
			}
		}
	}
	printf("%d", walk(sa, sb));
}