#include<stdio.h>
main(){
  int n,g[]={0,5,8,13,15,15,20,23,28,30,30,30,30,30,30};
  scanf("%d", &n);
  printf("%d", (n/15*30 + g[n%15]) * 100);
}
