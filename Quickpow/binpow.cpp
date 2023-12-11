
// 快速幂
#include <iostream>
using namespace std;
#define ll long long
ll a, b, p;
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll re = binpow(a, b / 2);
    if (b % 2)
        return re * re * a;
    else
        return re * re;
}
int main()
{
    ll a, b, ans;
    cin >> a >> b;
    ans = binpow(a, b);
    cout << ans;
    return 0;
}

// P1226 【模板】快速幂 | 取余运算
#include <iostream>
using namespace std;
#define ll long long
ll a, b, p;
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll re = binpow(a, b / 2);
    if (b % 2)
        return re * re * a % p;
    else
        return re * re % p;
}
int main()
{
    ll ans;
    cin >> a >> b >> p;
    ans = binpow(a, b);
    cout << a << '^' << b << " mod " << p << '=' << ans;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2e5+5;
vector<ll> p;
ll bin_pow(ll a, ll b, ll p){
    int res = 1;
    while(b>0){
        if((b & 1) == 1)res = res * a % p;
        a  = (a*a)%p;
        b>>=1;
    }
    return res;
}
void solve(){
    ll a, b, p;
    cin >> a >> b >> p;
    cout << a << '^' << b << "mod" << p << '=' << bin_pow(a, b, p);
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
   
    ll tt;cin >> tt;
    while(tt--){
        solve();
    }
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
