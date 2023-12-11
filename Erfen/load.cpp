// P1163 银行贷款
#include<iostream>
using namespace std;
int main(){
    int a, w, m;
    scanf("%d %d %d",&a, &w, &m);
    double c,be = 0,end = 5, mid,ans = a;
    while((ans != 0)&&((end - be)>=0.0001)){
        ans = a;
        mid = (end+be)/2;
        for(int i = 0;i<m;i++){
            ans = ans*(1+mid) - w;
        }
        if(ans<0)be = mid;
        else if(ans>0)end = mid;
    }
    printf("%.1lf",mid*100);
    return 0;


}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e6+5;
ll a[p];ll n,m;
ll find(ll num){
    ll hei=n,low=1;
    while(hei>low){
        ll mid=low +(hei-low)/2;
        if(a[mid]>=num) hei=mid;
        else low=mid+1;
    }
    if(a[low]==num)return low;
    else return -1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        ll num,flag;
        cin>>num;
        flag=find(num);
        cout<<flag<<' ';
    }
    return 0;
}