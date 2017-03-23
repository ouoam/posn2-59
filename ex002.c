#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n){
    int i;
    for(i=n-1;i>=2;i--){
        if(n%i==0)return false;
    }
    return true;
}

main(){
    int a;
    scanf("%d",&a);
    if(isPrime(a)){
        printf("true");
    }else{
        printf("false");
    }
}
