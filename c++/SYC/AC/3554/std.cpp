#include <bits/stdc++.h>
using namespace std;
int n, m, k, head[10005], pos, u, v, w, dis[10005][105];
bool st[10005][105];
struct Edge
{
    int u, v, w, next;
} e[20005];
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
struct node
{
    int d, u, t;
    bool operator<(const node &t) const
    {
        return d > t.d;
    }
};
void Dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    priority_queue<node> q;
    dis[1][0] = 0;
    q.push({0, 1, 0});
    while (q.size())
    {
        auto cur = q.top();
        q.pop();
        if (st[cur.u][cur.t])
            continue;
        st[cur.u][cur.t] = true;
        for (int i = head[cur.u]; i; i = e[i].next)
        {
            int v = e[i].v, w = e[i].w, d = cur.d;
            if (w >= d)
                d += (w - cur.d + k - 1) / k * k;
            if (dis[v][(d + 1) % k] > d + 1)
                dis[v][(d + 1) % k] = d + 1, q.push({dis[v][(d + 1) % k], v, (d + 1) % k});
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    Dijkstra();
    printf("%d", dis[n][0] == 0x3f3f3f3f ? -1 : dis[n][0]);
    return 0;
}