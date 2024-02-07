#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, net;
} e[300005];
int n, m, head[100005], pos, u, v;
ll w[100005];
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
ll low[100005], dfn[100005], scc[100005];
ll minw[100005], cnt[100005];
int idx, cid, cur;
bool vis[100005];
stack<ll> s, z;
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
            z.push(cur);
            minw[cid] = min(minw[cid], w[cur]);
            vis[cur] = false;
            scc[cur] = cid;
        } while (cur != u);
        while (!z.empty())
        {
            if (w[z.top()] == minw[cid])
                cnt[cid]++;
            z.pop();
        }
    }
}
ll ans = 0, num = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &u, &v), addEdge(u, v);
    memset(minw, 0x3f, sizeof(minw));
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= cid; i++)
        ans += minw[i], num *= cnt[i], num %= int(1e9 + 7);
    printf("%lld %lld", ans, num);
    return 0;
}