#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int n;
int m[200005];
int a[200005], b[200005];
ll ans = 1;
int sta[200005][25], stb[200005][25];
int fia(int x, int y)
{
    int q = log2(y - x + 1);
    return min(sta[x][q], sta[y - (1 << q) + 1][q]);
}
int fib(int x, int y)
{
    int q = log2(y - x + 1);
    return min(stb[x][q], stb[y - (1 << q) + 1][q]);
}
void dfs(bool fl, int s, int step)
{
    // printf("%d %d %d\n", fl, s, step);
    if (s == n + 1)
    {
        ans += step;
        ans %= mod;
        return;
    }
    if (fl == 0)
        for (int l = s; l <= n; l++)
            dfs(1, l + 1, min(step, fia(s, l)));
    if (fl == 1)
        for (int l = s; l <= n; l++)
            dfs(0, l + 1, min(step, fib(s, l)));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("hole6.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", m + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        b[i] = m[i] - a[i], a[i]--;
        sta[i][0] = a[i];
        stb[i][0] = b[i];
    }
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i + (1 << (p - 1)) <= n; i++)
            sta[i][p] = min(sta[i][p - 1], sta[i + (1 << (p - 1))][p - 1]);
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i + (1 << (p - 1)) <= n; i++)
            stb[i][p] = min(stb[i][p - 1], stb[i + (1 << (p - 1))][p - 1]);
    dfs(0, 1, 1e9);
    dfs(1, 1, 1e9);
    printf("%lld", ans);
    return 0;
}