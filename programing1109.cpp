#include<stdio.h>
#include <algorithm>

struct data{
  int a,b;
}pair[1000002];

bool cmp(data a, data b){
  return a.a<b.a?true:false;
}

int temp[100002], a[100002];
long long int cou = 0;

void merge(int start, int end) {
  int min = (start + end) / 2, i = 0, j = 0, b2f = 0;
  int fi = start, bi = min, len = end - start;
  if(min - start > 1){
    merge(start, min);
  }
  if(end - min > 1){
    merge(min, end);
  }
  while (fi < min && bi < end && i < len){
    if (a[fi] > a[bi]) {
      temp[i] = a[bi];
      bi++;
      b2f++;
      printf("move b b2f%d cou%d fi%d bi%d i%d\n",b2f,cou,fi,bi,i);
    } else {
      temp[i] = a[fi];
      fi++;
      cou += b2f;
      printf("move f b2f%d cou%d fi%d bi%d i%d\n",b2f,cou,fi,bi,i);
    }
    i++;
  }
  while (fi < min){
    temp[i] = a[fi];
    fi++;
    cou += b2f;
    i++;
    printf("move f b2f%d cou%d fi%d bi%d i%d\n",b2f,cou,fi,bi,i);
  }
  while (j < i){
    a[start + j] = temp[j];
    j++;
  }
}

int main(){
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    pair[i].a = a;
    pair[i].b = b;
  }
  std::sort(pair, pair + n, cmp);
  for (size_t i = 0; i < n; i++) {
    printf("%d %d\n", pair[i].a, pair[i].b);
  }
  return 0;
}
