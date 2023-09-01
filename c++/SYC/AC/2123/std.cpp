#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[4][105];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    dp[0][1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[3][i - 1];
        dp[1][i] = dp[0][i];
        dp[2][i] = dp[1][i - 1];
        dp[3][i] = dp[2][i - 1];
    }
    while (scanf("%d", &n) != -1)
    {
        printf("%lld\n", dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n]);
    }
    return 0;
}