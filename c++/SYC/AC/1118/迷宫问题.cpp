#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[15][15];
int fx_8[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
bool f[15][15];
int dfs(int x, int y)
{
    // printf("%d %d\n",x,y);
    if (x == 1 && y == n)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + fx_8[i][0], ty = y + fx_8[i][1];
        // printf("(%d %d)=(%d %d) %d-<%d %d>\n",x,y,tx,ty,i,fx_8[i][0],fx_8[i][1]);
        if (tx > n || tx < 1 || ty > n || ty < 1||a[tx][ty]==1)
            continue;
        if (!f[tx][ty])
        {
            f[tx][ty] = 1;
            cnt += dfs(tx, ty);
            f[tx][ty] = 0;
        }
    }
    return cnt;
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
            scanf("%d", &a[i][j]);
    f[1][1] = 1;
    printf("%d", dfs(1, 1));
    return 0;
}