#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
struct Edge
{
    int u, v, w;
} e[1500005];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int n, m, pos, u, v;
void addEdge(int u, int v, int w = 0)
{
    e[++pos] = {u, v, w};
}
int f[100005];
void init()
{
    pos = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            addEdge(i, j, (i - j) * (i - j)), addEdge(j, i, (i - j) * (i - j));
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
int kruskal()
{
    sort(e + 1, e + pos + 1, cmp);
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i <= pos && cnt < n; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) == find(v))
            continue;
        ans += w;
        merge(u, v);
        cnt++;
        if (find(1) == find(n))
            return ans;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            merge(u, v);
        }
        printf("%d\n", kruskal());
    }
    return 0;
}