#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, m, k, sx, sy;
char a[15][15];
bool vis[15][15];
bool dfs(int x, int y, int step)
{
    vis[x][y] = 1;
    if (x < 1 || y < 1 || x > n || y > m || a[x][y] == 'X')
        return 0;
    // printf("%d %d %d\n", x, y, step);
    if (step == k)
    {
        if (a[x][y] == 'D')
            return 1;
        return 0;
    }
    if (a[x][y] == 'D')
        return 0;
    bool ans = 0;
    if (vis[x + 1][y] == 0)
    {
        vis[x + 1][y] = 1;
        if (dfs(x + 1, y, step + 1))
            return 1;
        vis[x + 1][y] = 0;
    }
    if (vis[x - 1][y] == 0)
    {
        vis[x - 1][y] = 1;
        if (dfs(x - 1, y, step + 1))
            return 1;
        vis[x - 1][y] = 0;
    }
    if (vis[x][y - 1] == 0)
    {
        vis[x][y - 1] = 1;
        if (dfs(x, y - 1, step + 1))
            return 1;
        vis[x][y - 1] = 0;
    }
    if (vis[x][y + 1] == 0)
    {
        vis[x][y + 1] = 1;
        if (dfs(x, y + 1, step + 1))
            return 1;
        vis[x][y + 1] = 0;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (scanf("%d%d%d", &n, &m, &k), n)
    {
        memset(vis,0,sizeof vis);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                    sx = i, sy = j;
            }
        // printf("(%d %d)\n", sx, sy);
        puts(dfs(sx, sy, 0) ? "YES" : "NO");
    }
    return 0;
}