#include <stdio.h>
int temp[100002], a[100002] = {9, 8, 1, 3, 7, 2, 6, 4, 0, 5, 1};

void merge(int start, int end) {
	int len = end - start;
	int range = 1, begin;
	while (range < len) {
		range *= 2;
		begin = start;
		while (begin < end) {
			int along = (range + begin > end) ? end - begin : range;
			int mid = begin + range / 2, i = 0, j = 0;
			int fi = begin, bi = mid, en = begin + along;
			if (mid > end || along == 1)
				break;
			while (fi < mid && bi < en && i < along) {
				if (a[fi] > a[bi]) {
					temp[i] = a[bi];
					bi++;
				} else {
					temp[i] = a[fi];
					fi++;
				}
				i++;
			}
			while (fi < mid) {
				temp[i] = a[fi];
				fi++;
				i++;
			}
			while (j < i) {
				a[begin + j] = temp[j];
				j++;
			}
			begin += range;
		}
	}
}

main() {
	int n = 6;
	merge(0, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
