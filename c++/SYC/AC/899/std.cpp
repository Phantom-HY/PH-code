#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int dfn[500005], low[500005];
bool isCut[500005];
int idx, CutNum;
void tarjan(int u, int root)
{
    dfn[u] = low[u] = ++idx;
    int cnt = 0;
    for (int i = head[u]; i; i = e[i].net)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v, root);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u] && (u != root || ++cnt > 1))
                CutNum += !isCut[u], isCut[u] = true;
        }
        else
            low[u] = min(low[u], dfn[v]);
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
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    printf("%d\n", CutNum);
    for (int i = 1; i <= n; i++)
        if (isCut[i])
            printf("%d ", i);
    return 0;
}