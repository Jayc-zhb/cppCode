#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll aa = 2e5 + 5;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++)
		p.emplace_back((a[i], a[i + n]));
	int ans = 0;
	for (int i = 1; i < n; i++)
		ans += (p[i].first - p[i - 1].first) + (p[i].second - p[i - 1].second);
	cout << ans << '\n';
	for (auto x : p)
		cout << x.first << ' ' << x.second << '\n';
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
