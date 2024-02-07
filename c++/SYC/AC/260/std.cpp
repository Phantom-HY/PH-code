#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[405][405];
ll b[405];
ll dp[405];
ll sum()
{
    ll num = -1e18;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = max(dp[i - 1] + b[i], b[i]);
        num = max(num, dp[i]);
    }
    return num;
}
ll ans = -1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int st = 1; st <= n; st++)
    {
        memset(b, 0, sizeof(b));
        for (int ed = st; ed <= n; ed++)
        {
            for (int i = 1; i <= m;i++)
                b[i]+=a[ed][i];
            ans = max(ans, sum());
        }
    }
    printf("%lld\n", ans);
    return 0;
}