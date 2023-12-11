#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 1e5+5;
int a[qwe];
// bool vis[qwe];
void sove(){
    int n;cin >> n;
    int ma = 0;
    memset(a, 0, sizeof(a));
    for(int i = 1;i<=n;i++){
        int x;cin >> x;
        while(x>n){
            x >>= 1;
        }
        a[x] ++;
    }
    
    for(int i = n;i>=1;i--){
        if(a[i] == 0){cout << "NO\n";return;}
        while(a[i]>1)a[i/2]++, a[i]--;
    }
    for(int i = 1;i<=n;i++){
        if(a[i]!= 1){cout << "NO\n";return;}
    }
    cout << "YES\n";
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
    int T;cin >> T;
    while(T--){
        sove();
    }
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
