#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nL, nR;
struct Edge
{
    int u, v, net;
} e[100005];
int n, m, head[100005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int sel[100005];
bool vis[100005];
bool match(int u)
{
    for (int i = head[u]; i; i = e[i].net)
    {
        int v = e[i].v;
        if (!vis[v])
        {
            vis[v] = true;
            if (!sel[v] || match(sel[v]))
            {
                sel[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &nL, &nR, &m);
    n = nL + nR;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        v += nL;
        addEdge(u, v);
    }
    for (int i = 1; i <= nL; i++)
    {
        memset(vis, 0, sizeof(vis));
        ans += match(i);
    }
    printf("%d\n", ans);
    return 0;
}