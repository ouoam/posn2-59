#include <stdio.h>

int max(int a,int b){
  return a>b?a:b;
}

struct node{
  int val;
  node *left,*right;
  node(int val){
    this->val   = val;
    this->left  = NULL;
    this->right = NULL;
  }
};

node *treeAdd(node *thisN, int val){
  if(!thisN) return new node(val);

  if(val <= thisN->val){
    thisN->left  = treeAdd(thisN->left,  val);
  }else{
    thisN->right = treeAdd(thisN->right, val);
  }
  return thisN;
}

void treeIn(node *thisN) {
  if(!thisN) return;
  treeIn(thisN->left);
  printf("%d ", thisN->val);
  treeIn(thisN->right);
}

void treePre(node *thisN) {
  if(!thisN) return;
  printf("%d ", thisN->val);
  treePre(thisN->left);
  treePre(thisN->right);
}

void treePost(node *thisN) {
  if(!thisN) return;
  treePost(thisN->left);
  treePost(thisN->right);
  printf("%d ", thisN->val);
}

int treeSize(node *thisN){
  if(!thisN) return 0;
  return 1 + treeSize(thisN->left) + treeSize(thisN->right);
}

int treeDeep(node *thisN){
  if(!thisN) return 0;
  return 1 + max( treeDeep(thisN->left), treeDeep(thisN->right) );
}

int treeMin(node *thisN){
  if(!thisN->left) return thisN->val;
  treeMin(thisN->left);
}

int treeMax(node *thisN){
  if(!thisN->right) return thisN->val;
  treeMax(thisN->right);
}

bool treeFind(node *thisN, int val){
  if(!thisN) return false;
  if(thisN->val==val) return true;
  if(val <= thisN->val){
    if(treeFind(thisN->left,  val)) return true;
  }else{
    if(treeFind(thisN->right, val)) return true;
  }
  return false;
}


int main() {
  int data[]={8,6,1,2,7,3,4,9,0,5},n=10,i;
  node *tree;
  tree=NULL;
  for(i=0;i<n;i++){
    tree=treeAdd(tree,data[i]);
  }
  printf("\nIn   : ");  treeIn(tree);
  printf("\nPre  : ");  treePre(tree);
  printf("\nPost : ");  treePost(tree);
  printf("\nSize : %d", treeSize(tree));
  printf("\nDeep : %d", treeDeep(tree));
  printf("\nMin  : %d", treeMin(tree));
  printf("\nMax  : %d", treeMax(tree));
  printf("\nFind : %s", treeFind(tree,1)==true?"true":"false");
  return 0;
}
