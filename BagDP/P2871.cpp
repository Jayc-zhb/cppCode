#include<bits/stdc++.h>
using namespace std;
#define ma 12885
int w[ma],d[ma],v[ma];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>w[i]>>d[i];
        for(int l = m;l>=w[i];l--){
            v[l] = max(v[l], v[l-w[i]]+d[i]);
        }
    }
    cout<<v[m];
    return 0;
}