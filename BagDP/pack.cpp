#include<bits/stdc++.h>
using namespace std;
int a[105], b[105], v[1005];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i = 0;i<m;i++){
        cin>>a[i]>>b[i];
        for(int j=t;j>= a[i];j--)
        v[j] = max(v[j], v[j-a[i]]+b[i]);
    }
    cout<<v[t];
    return 0;
}
