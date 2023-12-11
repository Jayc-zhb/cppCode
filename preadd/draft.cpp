#include<iostream>
using namespace std;
int main(){
    int a[100], pre[101]={0}, n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    int c, b;
    scanf("%d %d", &b, &c);
    cout<<pre[c+1]-pre[b];
    return 0;
}