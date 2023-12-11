#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2e5+5;
vector<ll> p;
void exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;return;
    }
    exgcd(b, a%b, y, x);
    y -=a/b*x;
}
void solve(){
    ll a, p;
    cin >> a >> p;
    if(__gcd(a, p)!=1){
        cout << "invalid\n";
    }
    else{
        ll x, y;
        exgcd(a, p, x, y);
        cout << (x%p + p)%p << '\n';
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
    ll tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
    }
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
