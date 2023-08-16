#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, s;
int a[100005];
int dp[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= n; j++)
            if (a[j] <= i)
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
    if (dp[s] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", dp[s]);
    return 0;
}