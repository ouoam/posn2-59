#include <stdio.h>
#include <algorithm>

struct data{
  int sou,des;
}warp[1000002];

struct blog{
  bool mark,block;
}room[500002];

bool cmp(data a, data b){
  return a.sou<b.sou?true:false;
}

int main() {
  int n,m,k,a,b,max=0;
  scanf("%d %d %d",&n,&m,&k);
  for (int i = 0; i < m; i++) {
    scanf("%d %d",&warp[i].sou,&warp[i].des);
  }
  std::sort(warp,warp+m,cmp);
  for (int i = 0; i < k; i++) {
    scanf("%d",&a);
    room[a].block = true;
  }
  room[1].mark = true;
  a=0;
  for(int i = 1; i <= n; i++){
    if(room[i].mark){
      max=i;
      if(!room[i].block)room[i+1].mark=true;
      while(warp[a].sou<i)a++;
      while(warp[a].sou==i&&a<m){
        room[warp[a].des].mark = true;
        a++;
      }
    }
  }
  if(max==n){
    printf("1");
  }else{
    printf("0 %d",max);
  }
}
