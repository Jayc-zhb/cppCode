#include<bits/stdc++.h>
using namespace std;
const long long ma = 2*1e5+5;
int a[ma] = {0},pre[ma]={0};
int main(){
    int n,ans = -2147483647;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(i==1)pre[i] = a[i];
        else pre[i] = max(a[i], pre[i-1]+a[i]);
        ans = max(ans,pre[i]);
    }
    cout<<ans;
}