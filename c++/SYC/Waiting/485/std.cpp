#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w[405];
int dp[405][405], sum[405], ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i), dp[i][i] = w[i];
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int i = l; i < r; i++)
                if (dp[l][i] == dp[i + 1][r])
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
            for (int i = l; i < r; i++)
                for (int j = i + 1; j < r; j++)
                    if (dp[l][i] == dp[j + 1][r])
                        dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][j] + dp[j + 1][r]);
            ans = max(ans, dp[l][r]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c", dp[i][j], " \n"[j == n]);
    printf("%d", ans);
    return 0;
}