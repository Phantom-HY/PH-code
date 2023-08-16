#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[25][25], cnt[25], ans;
bool f[25];
void dfs(int x, int step)
{
    if (x == n + 1)
    {
        ans = max(ans, step);
        return;
    }
    if (step + cnt[x] <= ans)
        return;
    for (int i = 1; i <= n; i++)
        if (!f[i])
        {
            f[i] = 1;
            dfs(x + 1, step + a[x][i]);
            f[i] = 0;
        }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]), cnt[i] = max(cnt[i], a[i][j]);
    for (int i = n - 1; i >= 1; i--)
        cnt[i] += cnt[i + 1];
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}