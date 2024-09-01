#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105], t;
int dp[2005][2005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), t += a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = t; j >= 0; j--)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j >= a[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]]);
            if (j < a[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][a[i] - j] + j);
        }
    if (dp[n][0] != 0)
        printf("%d\n", dp[n][0]);
    else
        printf("Impossible");
    return 0;
}