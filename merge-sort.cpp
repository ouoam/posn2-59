#include<stdio.h>
int temp[100002], a[100002]={9,8,1,3,7,2,6,4,0,5};

void merge(int start, int end) {
  int min = (start + end) / 2, i = 0, j = 0;
  int fi = start, bi = min, len = end - start;
  if (min - start > 1)
    merge(start, min);
  if (end - min > 1)
    merge(min, end);
  while (fi < min && bi < end && i < len) {
    if (a[fi] > a[bi]) {
      temp[i] = a[bi];
      bi++;
    } else {
      temp[i] = a[fi];
      fi++;
    }
    i++;
  }
  while (fi < min) {
    temp[i] = a[fi];
    fi++;
    i++;
  }
  while (j < i) {
    a[start + j] = temp[j];
    j++;
  }
}

main() {
  int n=10;
  merge(0, n);
  for (int i = 0; i < n; i++)
    printf("%d ",a[i]);
}
