#include <stdio.h>

#define sumto(a) a *(a + 1) / 2

/*
int sumto(int a){
	int sum=0;
	while(a>0){
		sum+=a--;
	}
	return sum;
}
*/

int main() {
	int a = 0;
	for (a = 0; a < 10000; a++)
		printf("%d\n", sumto(a));
}
