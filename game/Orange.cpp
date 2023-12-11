#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll ma = 2*1e6+5;
ll a[ma] = {0},pre[ma] = {0};
int main(){
    ll n, k,sum=0,maxn=0;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
        if(k){
            if(i >=k){
                maxn = max(maxn,pre[i]-pre[i-k]);
            }
        }
        sum +=a[i];
    }
    cout<<sum-maxn;
    return 0;
}