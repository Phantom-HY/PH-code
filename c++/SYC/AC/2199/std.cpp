#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[10005];
int sum[10005];
int dp[10005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + a[i + 1];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = sum[i];
        for (int j = 1; j < i - 2; j++)
            dp[i] = max(dp[i], dp[j] + sum[i]);
        ans = max(ans, dp[i]);
        // printf("%d ", dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}