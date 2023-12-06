#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int n, t;
bool a[105][105];
int sel[105][105][2];
bool vis[105][105];
bool match(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int tx = x + fx_4[i][0];
        int ty = y + fx_4[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && !a[tx][ty])
            if (!vis[tx][ty])
            {
                vis[tx][ty] = true;
                if (sel[tx][ty][0] == 0 || match(sel[tx][ty][0], sel[tx][ty][1]))
                {
                    sel[tx][ty][0] = x;
                    sel[tx][ty][1] = y;
                    return true;
                }
            }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                continue;
            memset(vis, false, sizeof(vis));
            if (match(i, j))
                ans++;
        }
    printf("%d\n", ans / 2);
    return 0;
}