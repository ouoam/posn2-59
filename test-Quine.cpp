#include<stdio.h>
main(){
    char *c="#include<stdio.h>%cmain(){%c%cchar *c=%c%s%c;%c%cprintf(c,10,9,34,c,34,10,9,10);%c}";
    printf(c,10,10,9,34,c,34,10,9,10);
}
