#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, len;
int deep[100005];
vector<int> child[100005];
int fa[100005][21];
int maxid[100005];
void fun(int x, int y)
{
    maxid[x] = max(x, maxid[y]);
    deep[x] = deep[y] + 1;
    for (int i = 1; i <= log2(deep[x]); i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto &&i : child[x])
        fun(i, x);
}
int lca(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    while (deep[x] != deep[y])
        x = fa[x][int(log2(deep[x] - deep[y]))];
    if (x == y)
        return x;
    for (int i = log2(deep[x]); i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &fa[i][0]);
        child[fa[i][0]].push_back(i);
    }
    for (auto &&i : child[0])
        fun(i, 0);
    scanf("%d", &q);
    while (q--)
    {
        int a, b;
        scanf("%d%d%d", &len, &a, &b);
        len -= 2;
        a = lca(a, b);
        while (len--)
            scanf("%d", &b), a = lca(a, b);
        printf("%d\n", maxid[a]);
    }
    return 0;
}