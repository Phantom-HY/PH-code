#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, a[1005], b[1005];
ll dp[1005][1005];
ll ans;
ll cnt;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        ans = cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), b[i] = a[i], cnt += a[i];
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + a[i];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                ans = max(ans, dp[i][j]);
            }
        printf("%lld\n", cnt-ans);
    }
    return 0;
}