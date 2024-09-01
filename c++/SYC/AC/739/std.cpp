#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int num[105];
vector<int> chi[105];
int dp[105][105];
void fun(int x)
{
    dp[x][1] = num[x];
    for (auto &&v : chi[x])
    {
        fun(v);
        for (int j = n; j >= 0; j--)
            for (int k = 1; k < j; k++)
                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[v][k]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        chi[a].push_back(i);
        num[i] = b;
    }
    n++;
    fun(0);
    printf("%d", dp[0][n]);
    return 0;
}