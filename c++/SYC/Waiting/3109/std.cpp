#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000005], b[2000005];
struct Edge
{
    int u, v, net;
} e[2000005];
int n, m, k, head[2000005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int d[2000005];
int low[2000005], dfn[2000005], scc[2000005], siz[2000005];
int idx, cid, cur;
bool vis[2000005];
stack<int> s;
void init()
{
    idx = cid = cur = pos = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(scc, 0, sizeof(scc));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(siz, 0, sizeof(siz));
    while (!s.empty())
        s.pop();
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
int t;
int id[2000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        init();
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &a[i], &b[i]);
        for (int i = 1; i <= k; i++)
        {
            int len;
            scanf("%d", &len);
            for (int j = 1; j <= len; j++)
                scanf("%d", &id[j]), d[id[j]] = i;
            for (int j = 1; j < len; j++)
                for (int k = j+1; k <= len; k++)
                {
                    u = id[j], v = id[k];
                    addEdge(u + n, v), addEdge(u, v + n), addEdge(v + n, u), addEdge(v, u + n);
                }
        }
        for (int i = 1; i <= m; i++)
        {
            u = a[i], v = b[i];
            if (d[u] != d[v])
                addEdge(u + n, v), addEdge(v + n, u);
        }
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i])
                tarjan(i);
        bool flag = 1;
        for (int i = 1; i <= pos; i++)
            if (scc[i] == scc[i + n])
            {
                puts("NIE");
                flag = 0;
                break;
            }
        if (flag)
            puts("TAK");
    }
    return 0;
}