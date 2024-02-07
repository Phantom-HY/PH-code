#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int low[100005], dfn[100005], scc[100005], siz[100005];
int idx, cid, cur;
bool vis[100005];
stack<int> s;
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
    int i = max_element(siz + 1, siz + cid + 1) - siz;
    printf("%d\n%d\n", cid, siz[i]);
    for (int j = 1; j <= n; j++)
    {
        if (siz[scc[j]] == siz[i])
        {
            i = scc[j];
            break;
        }
    }
    for (int j = 1; j <= n; j++)
        if (scc[j] == i)
            printf("%d ", j);
    return 0;
}