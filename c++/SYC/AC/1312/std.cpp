#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int w[1005], c[1005];
int dp[2005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", w + i, c + i);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    printf("max=%d\n", dp[m]);
    return 0;
}