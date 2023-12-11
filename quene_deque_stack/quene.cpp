#include <bits/stdc++.h>
using namespace std;
deque<int> d;
const int qw = 1e6+5;
int a[qw];
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
	int n, k;cin >> n >>k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		while(!d.empty() && d.front()+k<=i)d.pop_front();
		while(!d.empty() &&a[d.back()]>=a[i])d.pop_back();
		d.push_back(i);
		if(i>=k)cout << a[d.front()] << ' ';
	}
	cout << endl;
	d.clear();
	for(int i = 1;i<=n;i++){
		while(!d.empty() &&d.front()+k<=i)d.pop_front();
		while(!d.empty() &&a[d.back()]<=a[i])d.pop_back();
		d.push_back(i);
		if(i>=k)cout << a[d.front()] << ' ';
	}
	cout << '\n';
	//=====================================
#ifdef LOCAL
	cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
	return 0;
}
