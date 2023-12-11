#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    a[n+1]=1e6+1;
    sort(a,a+n+2);
    for(int i = 0;i<m;i++){
        cin>>b[i];
         int hei = n+1,low=0,mid;
        while(hei>low){
            mid = low+(hei-low)/2;
            if(a[mid]>b[i])hei = mid;
            else if(a[mid]<=b[i])low = mid+1;
        }
        cout<<n+2-low<<' ';
    }
}