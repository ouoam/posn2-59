#include <stdio.h>
int temp[100002], a[100002];
long long int cou = 0;

void merge(int start, int end) {
	int min = (start + end) / 2, i = 0, j = 0, b2f = 0;
	int fi = start, bi = min, len = end - start;
	if (min - start > 1) {
		merge(start, min);
	}
	if (end - min > 1) {
		merge(min, end);
	}
	while (fi < min && bi < end && i < len) {
		if (a[fi] > a[bi]) {
			temp[i] = a[bi];
			bi++;
			b2f++;
		} else {
			temp[i] = a[fi];
			fi++;
			cou += b2f;
		}
		i++;
	}
	while (fi < min) {
		temp[i] = a[fi];
		fi++;
		cou += b2f;
		i++;
	}
	while (j < i) {
		a[start + j] = temp[j];
		j++;
	}
}

main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j]);
		}
		cou = 0;
		merge(1, n + 1);
		printf("%lld\n", cou);
	}
}
