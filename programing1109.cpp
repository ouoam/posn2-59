#include <algorithm>
#include <stdio.h>


struct data {
	long int a, b;
} pair[100002], temp[100002];

inline bool cmp(data a, data b) { return a.a < b.a ? true : false; }

inline void copy(data *ai, data *bi) {
	ai->a = bi->a;
	ai->b = bi->b;
}

long long int cou = 0;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = 0, j = 0;
	int fi = start, bi = mid, len = end - start;
	long long int b2f = 0;
	if (mid - start > 1) {
		merge(start, mid);
	}
	if (end - mid > 1) {
		merge(mid, end);
	}
	while (fi < mid && bi < end && i < len) {
		if (pair[fi].b > pair[bi].b) {
			copy(&temp[i], &pair[bi]);
			bi++;
			b2f += temp[i].a;
		} else {
			copy(&temp[i], &pair[fi]);
			fi++;
			cou += b2f + temp[i].a * (bi - mid);
		}
		i++;
	}
	while (fi < mid) {
		copy(&temp[i], &pair[fi]);
		fi++;
		cou += b2f + temp[i].a * (bi - mid);
		i++;
	}
	while (j < i) {
		copy(&pair[start + j], &temp[j]);
		j++;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%ld %ld", &pair[i].a, &pair[i].b);
	}
	std::sort(pair, pair + n, cmp);
	merge(0, n);
	printf("%lld", cou);
	return 0;
}
