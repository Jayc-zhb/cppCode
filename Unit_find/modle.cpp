#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p = 1e5+5;
ll a[p];
ll find(ll x);
void unit(ll x, ll y);
int main(){
    ll n,m;
    cin>>n>>m;
    while(m--){
        ll z,x,y;
        cin>>z>>x>>y;
        if(z==1)
            unit(x,y);
        else{
            if(find(x)==find(y))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}
ll find(ll x){
    return a[x] == x ? x: a[x] = find(a[x]);
}
void unit(ll x, ll y){
    a[find(x)] = find(y);
}