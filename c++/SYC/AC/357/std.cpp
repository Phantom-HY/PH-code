#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005], n, m;
int cnt[100005], dis[100005];
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i, cnt[i] = 1;
}
int find(int x)
{
    if (f[x] == x)
        return x;
    int fx = find(f[x]);
    dis[x] += dis[f[x]];
    return f[x] = fx;
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
    dis[fy] += cnt[fx];
    cnt[fx] += cnt[fy];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &m);
    n = 30000;
    init();
    while (m--)
    {
        char op;
        int x, y;
        scanf("%c ", &op);
        if (op == 'M')
        {
            scanf("%d %d\n", &x, &y);
            merge(x, y);
        }
        else
        {
            scanf("%d\n", &x);
            printf("%d\n", cnt[find(x)] - dis[x] - 1);
        }
    }
    return 0;
}