#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w,id;
} e[500005];
int n, m, pos;
bool vis[500005];
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
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w),e[i].id=i;
    sort(e + 1, e + m + 1, [](Edge a, Edge b) { return a.w < b.w; });
    init();
    for (int i = 0; i < m; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            merge(e[i].u, e[i].v);
            pos++;
            vis[e[i].id] = true;
        }
        if (pos == n - 1)
            break;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l;
        scanf("%d", &l);
        int x;
        bool flag = 0;
        for (int i = 1; i <= l; i++)
        {
            scanf("%d", &x);
            if (!vis[x])
                flag = 1;
        }
        puts(flag ? "NO" : "YES");
    }
    return 0;
}