#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll aa = 2e5 + 5;
void solve()
{
	int n;cin >> n;
	string s;cin >> s;
	vector<bool> vis(n, false);
	int ans = 0;
	for(int i = 0;i<n-1;i++){
		if(s[i] == 'A' && s[i+1] == 'B'){
			swap(s[i], s[i+1]), vis[i] = true;ans++;
		}
	}
	for(int i = 0;i<n-1;i++){
		if(s[i] == 'A' && s[i+1] == 'B' && !vis[i]){
			vis[i] = true;ans++;
		}
	}
	cout << ans << '\n';

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
	ll t;
	cin >> t;
	while (t--)
		solve();
		//=====================================
#ifdef LOCAL
	cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
	return 0;
}
