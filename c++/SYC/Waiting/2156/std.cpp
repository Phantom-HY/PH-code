#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[100005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
bool vis[100005];
int dis[100005];
int pr[100005];
int k;
void BellmanFord(int st)
{
    memset(dis, 0x3f, sizeof dis);
    dis[st] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j <= pos; j++)
        {
            int u = e[j].u, v = e[j].v, w = e[j].w;
            if (pr[u] + 1 > k)
                continue;
            if (dis[v] > dis[u] + w)
                pr[v] = pr[u] + 1;
            dis[v] = min(dis[v], dis[u] + w);
        }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    BellmanFord(1);
    if (dis[n] != 1061109567)
    {
        printf("%d ", dis[n]);
        exit(0);
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dis[i] != 1061109567)
            cnt = i;
    }
    printf("%d\n", cnt);
    printf("impossible");
    return 0;
}