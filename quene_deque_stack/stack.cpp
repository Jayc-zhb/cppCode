#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 3e6 + 20;
ll a[qwe], b[qwe];
stack<int> s;
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
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            b[i] = 0;
        else
            b[i] = s.top();
        s.push(i);
    }
    for (ll i = 1; i <= n; i++)
        cout << b[i] << ' ';
        //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
