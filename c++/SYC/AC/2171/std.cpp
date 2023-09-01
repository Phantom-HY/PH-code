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
} e[16005];
int n, m, head[305], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int f[305];
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
void Kruskal()
{
    sort(e + 1, e + 1 + m);
    int k = 0;
    for (int i = 1; i <= pos; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        // printf("%d(f[%d]:%d) %d(f[%d]:%d) %d\n", u, u, find(u), v, v, find(v), w);
        if (find(u) != find(v))
        {
            merge(u, v);
            // printf("%d %d\n", u, v);
            k++;
            if (k == n - 1)
            {
                printf("%d %d\n", k, w);
                return;
            }
        }
    }
    return ;
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
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    init();
    Kruskal();
    return 0;
}