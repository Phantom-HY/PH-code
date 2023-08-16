#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[405];
int sum[405];
int dp[405][405];
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), a[n + i] = a[i], dp[i][i] = dp[n + i][n + i] = 0;
    for (int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
        }
    ans = 1e9;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][i + n - 1]);
    printf("%d\n", ans);
    memset(dp, -0x3f, sizeof dp);
    for (int i = 1; i <= 2 * n; i++)
        dp[i][i] = 0;
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
        }
    ans = -1e9;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n - 1]);
    printf("%d\n", ans);
    return 0;
}