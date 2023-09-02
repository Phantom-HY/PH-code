#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int dp[2][50005];
int a[50005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    dp[0][1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + a[i];
        dp[1][i] = min(dp[0][i - 1], dp[0][i - 2]);
    }
    printf("%d\n", min(dp[0][n], dp[1][n]));
    return 0;
}