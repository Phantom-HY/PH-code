#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[15][15];
int dp[105][105][105], ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while(1)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        if (v == 0)
            break;
        a[x][y] = v;
    }
    for (int k = 1; k <= n + n; k++)
        for (int i = 1; i <= k && i <= n; i++)
            for (int j = 1; j <= k && j <= n; j++)
            {
                dp[k][i][j] = max(max(dp[k - 1][i][j], dp[k - 1][i - 1][j]), max(dp[k - 1][i][j - 1], dp[k - 1][i - 1][j - 1]));
                dp[k][i][j] += a[k - i + 1][i] + a[k - j + 1][j];
                if (i == j)
                    dp[k][i][j] -= a[k - i + 1][i];
                //printf("%d %d %d %d\n",k,i,j,ans);
                ans = max(ans, dp[k][i][j]);
            }
    printf("%d", ans);
    return 0;
}