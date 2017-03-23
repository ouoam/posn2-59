#include<stdio.h>
main(){
	int a,i=2,j;
	printf("input  : ");
	scanf("%d",&a);
	printf("output : ");
	while(a!=1){
		if(a%i==0){
			printf("%d*",i);
			a/=i;
		}else i++;
	}
}
