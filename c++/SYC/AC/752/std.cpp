#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int dp[15][15][2];
int pos;
int num[15];
int dfs(int len, int pre, int limit)
{
    if (!len)
        return 1;
    if (~dp[len][pre][limit])
        return dp[len][pre][limit];
    int res = 0;
    for (int i = 0; i <= (limit ? num[len] : 9); i++)
    {
        if (pre == 6 && i == 2 || i == 4)
            continue;
        res += dfs(len - 1, i, limit && i == num[len]);
    }
    return dp[len][pre][limit] = res;
}
int cal(int x)
{
    pos = 0, memset(dp, -1, sizeof dp);
    while (x)
        num[++pos] = x % 10, x /= 10;
    return dfs(pos, -1, true);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (scanf("%d%d", &n, &m), n)
        printf("%d\n", cal(m) - cal(n - 1));
    return 0;
}