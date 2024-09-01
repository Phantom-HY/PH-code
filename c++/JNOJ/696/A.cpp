#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &W) const
    {
        return w > W.w;
    }
} e[1000005];
struct node
{
    int id, k, v;
    bool operator<(const node &K) const
    {
        return k > K.k;
    }
} op[1000005];
int f[1000005], sie[1000005];
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i, sie[i] = 1;
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
        f[fx] = fy, sie[fy] += sie[fx];
}
int ans[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    init();
    for (int i = 1; i < n; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    for (int i = 1; i <= q; i++)
        scanf("%d%d", &op[i].k, &op[i].v), op[i].id = i;
    sort(e + 1, e + 1 + n);
    sort(op + 1, op + 1 + q);
    int r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (r < n - 1 && e[r + 1].w >= op[i].k)
        {
            r++;
            merge(e[r].u, e[r].v);
        }
        ans[op[i].id] = sie[find(op[i].v)] - 1;
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}