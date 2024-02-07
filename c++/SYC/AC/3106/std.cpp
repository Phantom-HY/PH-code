#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, net;
} e[100005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
char op[15];
int low[100005], dfn[100005], scc[100005], siz[100005];
int idx, cid, cur;
bool vis[100005];
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
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %s\n", &u, &v, &w, op);
        u++;
        v++;
        if (!strcmp(op, "AND"))
        {
            if (w == 0)
                addEdge(u, v+n),addEdge(v, u+n);
            else 
                addEdge(u+n,u),addEdge(v+n,v);
        }
        else if (!strcmp(op, "OR"))
        {
            if (w == 0)
                addEdge(u,u+n),addEdge(v,v+n);
            else
                addEdge(u+n,v),addEdge(v+n,u);
        }
        else if (!strcmp(op, "XOR"))
        {
            if (w == 0)
                addEdge(u+n,v+n),
                addEdge(u,v),
                addEdge(v+n,u+n),
                addEdge(v,u);
            else
                addEdge(u+n,v),
                addEdge(u,v+n),
                addEdge(v+n,u),
                addEdge(v,u+n);
        }
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= pos; i++)
        if (scc[i] == scc[i+n])
            puts("NO"),exit(0);
    puts("YES");
    return 0;
}