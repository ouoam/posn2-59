#include<stdio.h>

inline int abs(int a){
  return a>0?a:-a;
}

void print(int matrix[100][100], int n){
  printf("----START----\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%2d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("-----END-----\n");
}

main(){
  int matrix[100][100];
  int n,x,y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      matrix[i][j]=abs(j-y) + abs(i-x) + 1;
    }
  }
  print(matrix, n);
}
