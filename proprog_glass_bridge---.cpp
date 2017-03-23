#include<stdio.h>
int temp[100002], a[100002];

long long int merge(int start, int end) {
  int len = end - start;
  int range = 1, begin;
  long long int cou = 0;
  while(range < len){
    range *= 2;
    begin = start;
    while(begin < end){
      int along = (range+begin>end)?end-begin:range;
      int mid = begin + range/2, i = 0, j = 0, b2f = 0;
      int fi = begin, bi = mid, en = begin + along;
      if (mid > end || along == 1) break;
      while (fi < mid && bi < en && i < along) {
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
      while (fi < mid) {
        temp[i] = a[fi];
        fi++;
        cou += b2f;
        i++;
      }
      while (j < i) {
        a[begin + j] = temp[j];
        j++;
      }
      begin+=range;
    }
  }
  return cou;
}
main(){
  int t, n;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[j]);
    }
    printf("%lld\n", merge(1, n+1));
  }
}
