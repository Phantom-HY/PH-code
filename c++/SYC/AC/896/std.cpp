#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int low[200005], dfn[200005], scc[200005], dis[200005];
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
vector<Edge> edge;
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
            cur = s.top(), s.pop();
            vis[cur] = false;
            scc[cur] = cid;
        } while (cur != u);
    }
}
void SPFA(int s)
{
    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].net)
        {
            int v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                    vis[v] = true, q.push(v);
            }
        }
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
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back({u, v, w});
        addEdge(u, v, w);
    }
    tarjan(1);
    memset(head, 0, sizeof(head));
    pos = 0;
    for (auto i : edge)
    {
        u = i.u, v = i.v;
        if (scc[u] != scc[v])
            addEdge(scc[u], scc[v], i.w);
    }
    int x = n;
    n = cid;
    SPFA(scc[1]);
    printf("%d", dis[scc[x]]);
    return 0;
}