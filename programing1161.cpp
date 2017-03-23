#include<stdio.h>

struct queue {
  int x,y,i;
};

main(){
  queue Q[20002];
  int indexQ=0,a,b;
  bool check[102][102];
  char path[102][102],tempChar[3];
  scanf("%d %d", &a, &b);
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      scanf("%s", tempChar);
      path[i][j]=tempChar[0];
      check[i][j]=false;
    }
  }

  


  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      printf("%c ",path[i][j]);
    }
    printf("\n");
  }
}
