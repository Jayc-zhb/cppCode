#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll aa = 1e6 + 5;
int vis[30], A[30];
string c;

string f(string s)
{
	bool vis1[30];
	memset(vis1, 0, sizeof vis1);
	string sum = s;
	for (int i = 0; i < c.length(); i++)
	{
		string cur = "";
		vis1[c[i] - 'a'] = true;
		for (int j = 0; j < s.length(); j++)
		{
			if (vis1[s[j] - 'a'])
				continue;
			cur += s[j];
		}
		sum += cur;
		s = cur;
	}
	return sum;
}
void solve()
{
	memset(vis, 0, sizeof vis);
	string s;
	c = "";
	cin >> s;
	unordered_map<char, bool> mp;
	for (int i = s.length() - 1; i >= 0; i--)
		if (!mp[s[i]])
			c += s[i], mp[s[i]] = true;
	reverse(c.begin(), c.end());
	for (int i = 0; i < c.size(); i++)
		A[c[i] - 'a'] = i + 1;
	string ans;
	bool flag = false;
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += A[s[i] - 'a'];
		ans += s[i];
		vis[s[i] - 'a']++;
		if (sum == s.length())
		{
			if (f(ans) == s)
			{
				flag = true;
			}
		}
		else if (sum > s.length())
			break;
		if (flag)
			break;
	}
	if (flag)
		cout << ans << " " << c << endl;
	else
		cout << "-1" << endl;
}
signed main()
{
#ifdef LOCAL
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	clock_t c1 = clock();
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--)
		solve();
#ifdef LOCAL
	cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
	return 0;
}