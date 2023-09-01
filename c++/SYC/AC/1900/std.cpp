#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int dp[1005] = {1, 1, 1};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 100007;
    }
    printf("%d", dp[n]);
    return 0;
}