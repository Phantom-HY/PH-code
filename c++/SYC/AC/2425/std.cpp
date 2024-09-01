#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int qu[100005], pos;
struct node
{
    int fa, d, c;
    vector<int> chi;
} a[100005];
void add(int x, int y)
{
    a[x].fa = y;
    a[y].chi.push_back(x);
}
int f[100005][25], g[100005][25];
int dep[100005];
void fun(int x)
{
    dep[x] = dep[a[x].fa] + 1;
    f[x][0] = a[x].fa;
    g[x][0] = a[a[x].fa].c;
    for (int k = 1; k <= 20; k++)
        f[x][k] = f[f[x][k - 1]][k - 1],
        g[x][k] = g[f[x][k - 1]][k - 1] + g[x][k - 1];
    for (auto &&i : a[x].chi)
        fun(i);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].d, &a[i].c);
    qu[++pos] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].d > a[qu[pos]].d)
            while (pos && a[i].d > a[qu[pos]].d)
                add(qu[pos], i), pos--;
        qu[++pos] = i;
    }
    a[0].c = 1e9, a[0].d = 1e9;
    while (pos)
        add(qu[pos], 0), pos--;
    fun(0);
    while (q--)
    {
        int p, v;
        scanf("%d%d", &p, &v);
        if (a[p].c >= v)
        {
            printf("%d\n", p);
            continue;
        }
        v -= a[p].c;
        int x = p, ans = 0;
        for (int k = 20; k >= 0; k--)
        {
            if (g[x][k] <= v && (1 << k) <= dep[x])
            {
                // printf("%d %d %d %d %d\n", v, x, k, g[x][k], f[x][k]);
                v -= g[x][k];
                x = f[x][k];
                // printf("%d %d %d %d %d\n", v, x, k, g[x][k], f[x][k]);
            }
            if (v == 0)
                ans = x;
        }
        if (ans == 0)
            ans = f[x][0];
        printf("%d\n", ans);
    }
    return 0;
}