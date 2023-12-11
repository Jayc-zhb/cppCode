#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2e5+5;
ll a[qwe];
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
    ll n;cin >> n;
    a[0] = 1;
    // 定义式：
    // for(int i = 0;i<=n;i++){
    //     for(int j = 1;j<=i;j++){
    //         a[i] += a[j-1]*a[i-j];
    //         a[i]%=k; 遇到mod时，加上这个。
    //     }
    // }
    
    // 递推式：
    for(ll i = 1;i<=n;i++)a[i] = a[i-1]*(4*i-2)/(i+1);
    cout << a[n];
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
