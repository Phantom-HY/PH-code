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
} e[100005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int f[100005];
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
int Kruskal()
{
    int cnt = 0;
    sort(e + 1, e + 1 + m);
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) != find(v))
        {
            merge(u, v);
            sum++;
            cnt += w;
            if (sum == n - 1)
                return cnt;
        }
    }
    return -1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        cnt += w;
    }
    init();
    printf("%d", cnt - Kruskal());
    return 0;
}