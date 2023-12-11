#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2e5+5;
int n;
int a[55];
bool sta [55];
void dfs(int mid){
    if(mid == n+1){
        for(int i = 1;i<=n;i++)printf("%5d", a[i]);
        printf("\n");
    }
    for(int i = 1;i<=n;i++){
        if(!sta[i]){
            a[mid] = i;
            sta[i] = true;
            dfs(mid+1);
            sta[i] = false;
        }
    }
}
//=====================================
signed main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //=====================================
    cin >> n;
    dfs(1);
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
