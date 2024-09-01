#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, n, dp[5005][5005], sum[5005], p[5005][5005];
#define W(l, r) (sum[r] - sum[l - 1])
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x, dp[i][i] = 0, p[i][i] = i;
    }
    for (int l = n; l; l--)
        for (int r = l + 1; r <= n; r++)
            for (int k = p[l][r - 1]; k <= p[l + 1][r]; k++)
            {
                // printf("\n%d %d\n", dp[l][k] + dp[k + 1][l] + W(l, r), dp[l][r]);
                if (dp[l][k] + dp[k + 1][r] + W(l, r) < dp[l][r])
                {
                    dp[l][r] = dp[l][k] + dp[k + 1][r] + W(l, r);
                    p[l][r] = k;
                }
            }
    printf("%d", dp[1][n]);
    return 0;
}