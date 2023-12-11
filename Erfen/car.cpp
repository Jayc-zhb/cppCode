//P1258 小车问题
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double s, v1, v2, a;
    scanf("%lf %lf %lf", &s, &v1, &v2);
    double t1= 0 , t2 = 1, mid, be = 0, end = s, b;
    do{
        mid = (be+end)/2.0;
        a=mid/v2;
        b = (mid-a*v1)/(v1+v2);
        t1 = a+(s-mid)/v1;
        t2 = a+b+(s-(a+b)*v1)/v2;
        if(t1<t2){
            end = mid;
        }
        else  be = mid;
    }while(fabs(t1 - t2)>1e-8);
    printf("%.6f", t1);
    return 0;
}