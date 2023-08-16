#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, w, c[25], ans = 1e9, a[25];
void dfs(int x, int s)
{
    if (s >= ans)
        return;
    if (x == n + 1)
    {
        ans = min(ans, s);
        return;
    }
    for (int i = 1; i <= s; i++)
        if (a[i] + c[x] <= w)
        {
            a[i] += c[x];
            dfs(x + 1, s);
            a[i] -= c[x];
        }
    a[s + 1] += c[x];
    dfs(x + 1, s + 1);
    a[s + 1] -= c[x];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++)
        scanf("%d", c + i);
    sort(c + 1, c + 1 + n, greater<>());
    a[0] = w;
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}