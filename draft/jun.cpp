#include"iostream"
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10005],n,temp;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i = 0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}