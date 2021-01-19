#include<stdlib.h>
#include<stdio.h>
long cread_alt(long *xp){
    long temp = 0;
    xp = xp? xp: &temp;
    int result = *xp;
    return result;
}
int main(){
    system("pause");
    return 0;
}