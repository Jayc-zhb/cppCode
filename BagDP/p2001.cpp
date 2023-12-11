//	[NOIP2001 普及组] 装箱问题
#include <iostream>
using namespace std;
const int maxn = 20005;
int a[maxn], b[maxn];
int main()
{
    int v, n;
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= a[i]; j--)
        {
            if (b[j - a[i]] + a[i] > b[j])
                b[j] = b[j - a[i]] + a[i];
        }
    }
    cout << v - b[v];
    return 0;
}

// P1048[NOIP2005 普及组] 采药
#include <iostream>
using namespace std;
const int l = 1000 + 5;
int ti[l], v[l], f[l];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ti[i] >> v[i];
        for (int j = t; j >= ti[i]; j--)
        {
            if (f[j - ti[i]] + v[i] > f[j])
                f[j] = f[j - ti[i]] + v[i];
        }
    }

    cout << f[t];
    return 0;
}

// P2871 [USACO07DEC]Charm Bracelet S  洛谷
#include <iostream>
using namespace std;
const int M = 12880 + 5;
int we[M], d[M], v[M];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> we[i] >> d[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= we[i]; j--)
        {
            if (v[j - we[i]] + d[i] > v[j])
                v[j] = v[j - we[i]] + d[i];
        }
    }
    cout << v[m];
    return 0;
}

// P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles
#include <iostream>
#include <algorithm>
using namespace std;
const int ma = 1000 + 5;
int a[ma][ma], b[ma][ma];
int main()
{
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b[i][j] = a[i][j] + max(b[i - 1][j], b[i - 1][j - 1]);
        }
    }
    sort(b[n], b[n] + n + 1);
    cout << b[n][n];
    return 0;
}