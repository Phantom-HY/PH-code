#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[200005];
int n, m, head[200005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int low[200005], dfn[200005], scc[200005], siz[200005];
int idx, cid, cur;
bool vis[200005];
stack<int> s;
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
    scanf("%d", &n);
    int x;
    for (int i = 1; i <= n; i++)
        scanf(" %d", &x), addEdge(i, x, 0);
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
        if (siz[scc[i]] != 1)
            ans = min(ans, siz[scc[i]]);
    }
    printf("%d\n", ans);
    return 0;
}