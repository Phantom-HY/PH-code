#include <bits/stdc++.h>
using namespace std;
long long dp[2][21][162], ans, len, num[21], sum, L, R;
long long dfs(bool limit, int pos, int cur)
{
    if (!pos)
        return cur == sum;
    if (~dp[limit][pos][cur])
        return dp[limit][pos][cur];
    int b = limit ? num[pos] : 9;
    long long res = 0;
    for (int i = 0; i <= b; i++)
        if (cur + i <= sum)
            res += dfs(limit && i == b, pos - 1, cur + i);
    return dp[limit][pos][cur] = res;
}
long long calc(long long x)
{
    len = 0;
    memset(dp, -1, sizeof dp);
    while (x)
        num[++len] = x % 10, x /= 10;
    return dfs(true, len, 0);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%lld%lld", &L, &R);
    for (int i = 1; i <= 162; i++)
    {
        sum = i;
        ans = max(ans, calc(R) - calc(L - 1));
    }
    printf("%lld", ans);
    return 0;
}