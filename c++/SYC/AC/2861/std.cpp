#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int r[6005];
int fa[6005];
vector<int> chi[6005];
int dp[6005][2];
void fun(int x)
{
    if (chi[x].size() == 0)
    {
        dp[x][1] = r[x];
        return;
    }
    for (auto &&i : chi[x])
    {
        fun(i);
        dp[x][0] += max(dp[i][1], dp[i][0]);
    }
    dp[x][1] = r[x];
    for (auto &&i : chi[x])
        dp[x][1] += dp[i][0];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++)
    {
        int k, l;
        scanf("%d%d", &l, &k);
        fa[l] = k;
        chi[k].push_back(l);
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] == 0)
        {
            fun(i);
            printf("%d", max(dp[i][1], dp[i][0]));
            exit(0);
        }
    return 0;
}