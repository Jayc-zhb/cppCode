#include"stdio.h"

int main(){
    float a, b, c, t;
    scanf("%f %f %f", &a, &b, &c);
    if(a > c){
        t = a,a = c,c = t;
    }
    if(a > b){
        t = a,a = b,b = t;
    }
    if(b > c){
        t = b,b = c,c = t;
    }
    printf("%5.2f, %5.2f, %5.2f", a, b, c);
}