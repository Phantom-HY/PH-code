#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w;
} e[500005];
int n, m, pos, u, v, w;
int f[500005];
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e, e + m, [](Edge a, Edge b) { return a.w < b.w; });
    pos = 0;
    ll ans = 0;
    init();
    for (int i = 0; i < m; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            merge(e[i].u, e[i].v);
            pos++;
            ans+=e[i].w;
        }
        if (pos == n - 1)
            break;
    }
    printf("%lld\n", ans);
    return 0;
}