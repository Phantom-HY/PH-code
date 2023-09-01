#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
} e[400005];
int n, m, head[200005], pos, u, v, w;
int k;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int f[200005];
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
}
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
ll Kruskal()
{
    ll cnt = 0;
    sort(e + 1, e + 1 + m);
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        // printf("%d(f[%d]:%d) %d(f[%d]:%d) %d\n", u, u, find(u), v, v, find(v), w);
        if (find(u) != find(v))
        {
            merge(u, v);
            sum++;
            cnt += w;
            if (sum == n - k)
                return cnt;
        }
    }
    return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    init();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    printf("%lld", Kruskal());
    return 0;
}