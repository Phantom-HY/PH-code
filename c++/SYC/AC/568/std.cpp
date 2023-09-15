#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10];
int h[10][10], l[10][10], f[10][10];
pair<int, int> v[10];
int k[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {0, 6, 7, 7, 7, 7, 7, 7, 7, 6}, {0, 6, 7, 8, 8, 8, 8, 8, 7, 6}, {0, 6, 7, 8, 9, 9, 9, 8, 7, 6}, {0, 6, 7, 8, 9, 10, 9, 8, 7, 6}, {0, 6, 7, 8, 9, 9, 9, 8, 7, 6}, {0, 6, 7, 8, 8, 8, 8, 8, 7, 6}, {0, 6, 7, 7, 7, 7, 7, 7, 7, 6}, {0, 6, 6, 6, 6, 6, 6, 6, 6, 6}};
int ans;
void dfs(int x, int y, int sum)
{
    if (x == 10)
    {
        ans = max(ans, sum);
        return;
    }
    if (y == 10)
    {
        dfs(x + 1, 1, sum);
        return;
    }
    if (a[v[x].second][y] != 0)
    {
        dfs(x, y + 1, sum + a[v[x].second][y] * k[v[x].second][y]);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        int j = v[x].second;
        if (h[j][i] == 0 && l[y][i] == 0 && f[(j - 1) / 3 * 3 + (y - 1) / 3 + 1][i] == 0)
        {
            h[j][i] = 1;
            l[y][i] = 1;
            f[(j - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = 1;
            dfs(x, y + 1, sum + i * k[v[x].second][y]);
            h[j][i] = 0;
            l[y][i] = 0;
            f[(j - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = 0;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                h[i][a[i][j]] = 1,
                l[j][a[i][j]] = 1,
                f[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][a[i][j]] = 1;
            else
                v[i].first++;
            v[i].second = i;
        }
    sort(v + 1, v + 10);
    dfs(1, 1, 0);
    printf("%d", ans == 0 ? -1 : ans);
    return 0;
}