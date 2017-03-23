#include<stdio.h>
#define INF 5000000 //more than posible value
#define MAX 1000 //max node

struct edge{
  int des,weight;
  edge *next;
  edge(edge *next, int des, int weight){
    this->next = next;
    this->des = des;
    this->weight = weight;
  }
};

void find(int distance[], edge *street[], int sou, int des, int dis = 0){
  if(distance[sou]<=dis)return; //have short path before
  distance[sou]=dis;
  if(sou==des)return; //found destination

  edge *ptr=street[sou];
  while(ptr!=NULL){ //loop for go to other node
    find(distance, street, ptr->des, des, dis + ptr->weight); ////
    ptr=ptr->next;
  }
}

main(){
  int distance[ MAX + 1 ];
  int n,m,a,b,c,sou,des;
  edge *street[ MAX + 1 ];
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n ; i++){
    distance[ i ] = INF;
    street[ i ] = NULL;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c );
    street[ a ] = new edge(street[ a ], b, c);
  }
  scanf("%d %d", &sou, &des);
  find(distance, street, sou, des);
  printf("%d",distance[des]);
}
