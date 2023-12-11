// P2249 【深基13.例1】查找
#include<iostream>
using namespace std;
#define ll long long
const ll p = 1e6+5;
ll a[p] = {0};
int main(){
    ll n,m;
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 0;i<m;i++){
        ll num ;
        cin>>num; 
        ll be= 1,end = n,mid;
        while(end>be){
            mid = be+(end-be)/2;
            if(a[mid]>=num)end = mid;
            else if(a[mid]<num)be = mid+1;
        }
        if(a[be] == num)cout<<be<<' ';
        else cout<<-1<<' ';
    }
    return 0;
}