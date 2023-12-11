#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a [2005], b[2005];
deque<int> dp;
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
    int n, x, ans = 0;cin >> n;
    for(int i = 0;i<n;i++){
        cin >> x;
        dp.push_back(x);
    }
    int cnt;
    if(dp.front()>dp.back()) {cnt = dp.back();dp.pop_back();ans++;}
    else {cnt = dp.front();dp.pop_front();ans++;}
    while(!dp.empty()){
        if(cnt>dp.front()&&cnt>dp.back())break;
        if(cnt<dp.front()&&cnt<dp.back()){
            if(dp.back()>dp.front()){
                cnt = dp.front();
                dp.pop_front();
                ans++;
            }
            else{
                cnt = dp.back();
                dp.pop_back();
                ans++;
            }
        }
        else if(cnt<dp.front()){
            cnt = dp.front();
            dp.pop_front();
            ans++;
        }
        else{
            cnt = dp.back();
            dp.pop_back();
            ans++;
        }
    }
    cout << ans;
    //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
