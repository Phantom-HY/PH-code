#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, d;
struct node
{
    int a, b, t;
} a[305];
int ans = -1e9;
void fun(int x, int ti, int id, int step)
{
    if (id == m + 1)
    {
        ans = max(step, ans);
        return;
    }
    while (ti == a[id].t)
        step += a[id].b - abs(a[id].a - x), id++;
    if (x + d > n)
        fun(x + d - n, ti + 1, id, step);
    if (x - d < 1)
        fun(x - d + n, ti + 1, id, step);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].t);
    for (int i = 1; i <= n; i++)
        fun(i, 1, 1, 0);
    printf("%d", ans);
    return 0;
}