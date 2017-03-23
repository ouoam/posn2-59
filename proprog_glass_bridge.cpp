#include<stdio.h>

int a[100002], b[100002];

main(){
  int t, n, cou;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[j]);
      b[a[j]]=j;
    }
    cou = 0;
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= a[j]; k++) {
        if (b[k]>j) {
          cou++;
        }
      }
    }
    printf("%d",cou);
  }
}
