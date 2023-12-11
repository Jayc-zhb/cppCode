#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
struct node
{
    int num,pos;
}a[N];
vector<int> v;
int id[N];
bool cmp(node a,node b)
{
    return a.num > b.num;
}
int main()
{
    scanf("%d %d",&n,&m);
    int ans = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].num);
        a[i].pos = i;
    }
    sort(a,a+n,cmp);
    for(int i=0; i<m; i++)
    {
        id[i] = a[i].pos;
        ans += a[i].num;
    }
    cout<<ans<<endl;
    id[m]=n;
    sort(id,id+m+1);
    printf("%d ",id[1]);
    for(int i=1; i<m-1; i++)
    {
       printf("%d ",id[i+1]-id[i]);
    }
    if(m!=1) printf("%d\n",id[m]-id[m-1]);
}