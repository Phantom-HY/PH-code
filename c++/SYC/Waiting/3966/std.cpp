#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
struct Edge
{
    int u, v, net;
} e[500005];
int n, m, head[500005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
ll dp[500005][4];
int col[500005];
int f[3][2] = {{2, 3}, {1, 3}, {1, 2}};
bool vis[500005];
void fun(int x)
{
    vis[x] = 1;
    if (col[x] != 0)
    {
        dp[x][col[x]] = 1;
        for (int i = head[x]; i; i = e[i].net)
            if (!vis[e[i].v])
            {
                int v = e[i].v;
                fun(v);
                dp[x][col[x]] *= (dp[v][f[col[x] - 1][0]] + dp[v][f[col[x] - 1][1]]) % mod;
                dp[x][col[x]] %= mod;
            }
    }
    else
    {
        dp[x][1] = dp[x][2] = dp[x][3] = 1;
        for (int i = head[x]; i; i = e[i].net)
            if (!vis[e[i].v])
            {
                int v = e[i].v;
                fun(v);
                dp[x][1] *= (dp[v][2] + dp[v][3]) % mod;
                dp[x][1] %= mod;
                dp[x][2] *= (dp[v][1] + dp[v][3]) % mod;
                dp[x][2] %= mod;
                dp[x][3] *= (dp[v][1] + dp[v][2]) % mod;
                dp[x][3] %= mod;
            }
        // printf("(%d): %lld %lld %lld\n", x, dp[x][1], dp[x][2], dp[x][3]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", col + i);
    fun(1);
    // for (int i = 1; i <= n; i++)
    //     printf("%lld %lld %lld\n", dp[i][1], dp[i][2], dp[i][3]);
    printf("%lld", (dp[1][1] + dp[1][2] + dp[1][3]) % mod);
    return 0;
}