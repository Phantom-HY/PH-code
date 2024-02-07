#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int low[200005];
int dfn[200005];
int scc[200005];
int dis[200005];
int siz[200005];
int idx, cid, cur;
bool vis[200005];
stack<int> s;
struct Edge
{
    int u, v, w, net;
} e[500005];
int n, m, head[200005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++idx;
    s.push(u);
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].net)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        cid++;
        do
        {
            siz[cid]++;
            cur = s.top(), s.pop();
            vis[cur] = false;
            scc[cur] = cid;
        } while (cur != u);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    memset(vis, 0, sizeof(vis));
    int cnt = cid, num = (1 + cid) * cid / 2;
    for (int i = 1; i <= pos; i++)
        if (scc[e[i].u] != scc[e[i].v])
            if (!vis[scc[e[i].u]])
                vis[scc[e[i].u]] = true, cnt--, num -= scc[e[i].u];
    if (cnt == 1)
        printf("%d\n", siz[num]);
    else 
        printf("0\n");
    return 0;
}