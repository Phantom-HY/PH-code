#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, net = 0;
} e[500005];
int n, m, head[500005], pos = 1, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
vector<Edge> CutBridge;
int dfn[500005], low[500005], idx;
void tarjan(int u, int eIdx)
{
    dfn[u] = low[u] = ++idx;
    for (int i = head[u]; i; i = e[i].net)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                CutBridge.push_back({u, v});
        }
        else if (i != (eIdx ^ 1))
            low[u] = min(low[u], dfn[v]);
    }
}
bool cmp(Edge a, Edge b)
{
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}
void Cut_Bridge()
{
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0);
    sort(CutBridge.begin(), CutBridge.end(), cmp);
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
        addEdge(u, v);
        addEdge(v, u);
    }
    Cut_Bridge();
    for (int i = 0; i < CutBridge.size(); i++)
        printf("%d %d\n", CutBridge[i].u, CutBridge[i].v);
    return 0;
}