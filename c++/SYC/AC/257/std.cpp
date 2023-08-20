#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[1005][1005];
bool vis[1005][1005];
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
void fun(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 1 || !vis[x][y])
        return;
    vis[x][y] = 0;
    for (int i = 0; i < 4; i++)
        fun(x + fx_4[i][0], y + fx_4[i][1]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), vis[i][j] = 1;
    for (int i = 1; i <= m; i++)
        if (a[1][i] == 0)
            fun(1, i);
    for (int i = 1; i <= m; i++)
        if (a[n][i] == 0)
            fun(n, i);
    for (int i = 1; i <= n; i++)
        if (a[i][1] == 0)
            fun(i, 1);
    for (int i = 1; i <= n; i++)
        if (a[i][m] == 0)
            fun(i, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", vis[i][j], j == m ? '\n' : ' ');
    return 0;
}