#include<iostream>
using namespace std;
#define l long
const l p = 1e5+5;
l a[p] ={0};
l pre[p] = {0};
int main(){
    l n,m;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = a[i]+pre[i-1];
    }
    cin>>m;
    for(int i = 0;i<m;i++){
        l b,c;
        cin>>b;cin>>c;
        cout<<pre[c]-pre[b-1]<<endl;
    }
    return 0;
}