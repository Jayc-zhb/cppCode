#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool is_su_sum(ll p);
int main(){
    ll l,r,count=0;
    cin>>l>>r;
    ll i = pow(l-1,0.5);
    ll p = i*i+1;
    while(p<=r){
        if(is_su_sum(p))
            count++;
        i++;
        p = i*i+1;
    }
    cout<<count;
    return 0;
}
bool is_su_sum(ll p){
    for(int j = 2;j<=p/2;j++)
        if(p%j == 0)
            return false;
    return true;
}