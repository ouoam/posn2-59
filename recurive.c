#include<stdio.h>

int mystrlen(char *a) {
  if( *a == 0 ) return 0;
  else return 1 + mystrlen( a + 1 );
}

void strreverse(char *a, int b, int c ) {
  if ( c < 0 ) return;
  char temp;
  temp = *(a+c);
  *(a+c) = *(a+b-c-1);
  *(a+b-c-1) = temp;
  strreverse( a, b, c - 1 );
}

int myadd(int a, int b) {
  if ( b < 0 ) return 0;
  return a + myadd( 1, b - 1 );
}

int mymult(int a, int b) {
  if ( b == 0 ) return 0;
  return a + mymult( a, b - 1 );
}

int gcd(int a, int b){
  if ( a == 0 ) return b;
  return gcd( b % a, a );
}

int lcm(int a, int b){
  return a * b / gcd( a, b );
}

int main() {
  char a[] = "ABCDEFG";
  printf("mystrlen(a)   : %d\n", mystrlen( a ) );
  strreverse( a, mystrlen( a ), ( mystrlen( a ) - 1 ) / 2 );
  printf("strreverse(a) : %s\n", a );
  printf("myadd(100,50) : %d\n", myadd( 100, 50 ) );
  printf("mymult(50,2)  : %d\n", mymult( 50, 2 ) );
  printf("gcd(144,180)  : %d\n", gcd( 144, 180 ) );
  printf("lcm(144,180)  : %d\n", lcm( 144, 180 ) );
}
