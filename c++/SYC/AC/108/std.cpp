#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, g[505][505];
int u, v, w;
bool vis[505];
int dis[505];
int prim()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 0;
        for (int v = 1; v <= n; v++)
            if (!vis[v] && dis[v] < dis[u])
                u = v;
        vis[u] = 1;
        for (int v = 1; v <= n; v++)
            if (!vis[v] && g[u][v] < dis[v])
                dis[v] = g[u][v];
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 0x3f3f3f3f)
            return -1;
        res += dis[i];
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int res = prim();
    if (res == -1)
        puts("impossible");
    else
        printf("%d\n", res);
    return 0;
}