#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll qwe = 2e5 + 5;
ll ansa[20], ansb[20];
ll digit[20], mi[20], dp[20];
void solve(ll n, ll *ans)
{
    ll temp = n, len = 0;
    memset(digit, 0, sizeof(digit));
    while (n)
    {
        digit[++len] = n % 10;
        n /= 10;
    }
    for (int l = len; l >= 1; l--)
    {
        for (int i = 0; i <= 9; i++)// 
            ans[i] += dp[l - 1] * digit[l];
        for (int i = 0; i < digit[l]; i++)
            ans[i] += mi[l - 1];
        temp -= mi[l - 1] * digit[l]; // ��ȥ���λ��
        ans[digit[l]] += temp + 1;//���λ���ֵĴ���
        ans[0] -= mi[l - 1]; // ��ȥ��λ0
    }
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
    ll a, b;
    cin >> a >> b;
    mi[0] = 1;
    for (int i = 1; i <= 13; i++)
    {
        dp[i] = 10 * dp[i - 1] + mi[i - 1]; // dpת�Ʒ���
        mi[i] = mi[i - 1] * 10ll;
    } // dp[i]��ʾiλ�������ֳ��ֵĸ���
    solve(a - 1, ansa), solve(b, ansb);
    for (int i = 0; i < 10; i++)
        cout << ansb[i] - ansa[i] << ' ';

        //=====================================
#ifdef LOCAL
    cerr << "Time used: " << clock() - c1 << " ms" << '\n';
#endif
    return 0;
}
