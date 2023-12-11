#include<bits/stdc++.h>
using namespace std;
const long ma = 20000+5;
int v[ma]={0}, re[ma]={0};
int main(){
    int V,n;
    cin>>V;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>v[i];
        for(int j = V;j>=v[i];j--){
            re[j] = max(re[j],re[j-1]+v[i]);
        }
    }
    if(V-re[V]<=0)cout<<0;
    else cout<<V-re[V];
    return 0;
}