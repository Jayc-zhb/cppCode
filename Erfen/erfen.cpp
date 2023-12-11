#include <iostream>
using namespace std;
#define ll long long
const ll p = 1e6 + 5;
ll a[p];
int main()
{
    ll n, m, target;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        ll low = 1, hei = n, mid, ans = -1;
        cin >> target;
        mid = int((hei + low) / 2);
        while (hei >= low)
        {
            if (a[mid] >= target)
                hei = mid - 1;
            else
                low = mid + 1;
            mid = int((hei + low) / 2);
        }
        for (ll i = max(1ll, low - 3); i <= min(hei + 3, n); i++)
        {
            if (a[i] == target)
            {
                ans = i * 2;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}