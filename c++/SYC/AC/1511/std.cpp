#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n;
ll dp[100005];
int sum[4] = {1, 2, 5, 10};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    dp[0] = 1;
    for (int j = 0; j < 4; j++)
        for (int i = 1; i <= n; i++)
            if (sum[j] <= i)
                dp[i] += dp[i - sum[j]], dp[i] %= mod;
    printf("%lld", dp[n]);
    return 0;
}