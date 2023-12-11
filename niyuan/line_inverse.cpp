#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 4e6 + 5;
vector<ll> p;
ll inv[qwe];
void solve()
{
    ll n, p;
    cin >> n >> p;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
        // OI-WiKi上有推导公式
    }
    for (int i = 1; i <= n; i++)
        cout << inv[i] << '\n';
}
//=====================================
signed main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //=====================================
    ll tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
