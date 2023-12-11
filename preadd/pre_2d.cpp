#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2005;
ll a[qwe][qwe],pre[qwe][qwe];
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
    ll n, m, p, q, ans = INT_MIN;
    cin >> n >> m >> p >> q;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> a[i][j];
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
        }
    }
    for(int i = p;i<=n;i++){
        for(int j = q;j<=m;j++){
            ll mid = pre[i][j]-pre[i-p][j]-pre[i][j-q]+pre[i-p][j-q];
            ans = max(ans , mid);
        }
    }
    cout << ans;

    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
