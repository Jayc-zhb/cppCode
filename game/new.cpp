#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll num,a,b=1,sum = 0;
    cin>>num;
    while(num>0){
        a = num%10;
        if(num>0&&num<10){
            if(num<=4)
                sum = a*b;
            else
                sum = a*b*10;
        }
        b*=10;
        num/=10;
    }
    cout<<sum;
    return 0;
}