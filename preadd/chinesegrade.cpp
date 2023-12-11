#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p = 5*1e6;
ll re[p+5]={0}, pre[p+5]={0};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>re[i];
        pre[i] = re[i]-re[i-1];
    }
    while(m--){
        ll a, b,num;
        cin>>a>>b>>num;
        pre[a]+=num;
        pre[b+1]-=num;
    }
    for(int i = 1;i<=n;i++){
        re[i] = re[i-1]+pre[i];
    }
    sort(re+1,re+n+1);
    cout<<re[1];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  cin>>n>>p;
  vector <int>a(n+1),b(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i]-a[i-1];
  }
  while(p--){
    int x,y,z;
    cin>>x>>y>>z;
    b[x]+=z;
    b[y+1]-=z;
  }
  for(int i=1;i<=n;i++){
    a[i]=b[i]+a[i-1];
  }
  sort(a.begin()+1,a.end());
  cout<<a[1];
  return 0;
}
  