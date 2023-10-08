#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int T, n, m, k;
int a[505][505], st[505][505];
int vis[25];
int dfs(int x, int y)
{
    if (y == m + 1)
        x++, y = 1;
    if (x == n + 1)
        return 1;
    int sum = 0, S = st[x - 1][y] | st[x][y - 1];
    if (k - __builtin_popcount(S) < n + m - x - y + 1)
        return 0;
    for (int i = 1, t = -1; i <= k; i++)
    {
        if (S & (1 << i))
            continue;
        if (!a[x][y] || a[x][y] == i)
        {
            st[x][y] = S | (1 << i);
            if (++vis[i] == 1)
            {
                if (t == -1)
                    t = dfs(x, y + 1);
                sum = (sum + t) % mod;
            }
            else
                sum = (sum + dfs(x, y + 1)) % mod;
            --vis[i];
        }
    }
    return sum;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]), vis[a[i][j]]++;
        if (n + m - 1 > k)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}