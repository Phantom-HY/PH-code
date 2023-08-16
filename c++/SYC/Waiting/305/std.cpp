#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[25][25], ans;
void dfs(int x, int y, int step)
{
    // printf("%d %d %d\n",x,y,step);
    if (step > k)
        return;
    if (x == n && y == m)
    {
        if (step == k)
            ans++;
        return;
    }
    if (step == k)
        return;
    if (y+1<=m)dfs(x,y+1,step+a[x][y]);
    if (x+1<=n)dfs(x+1,y,step+a[x][y]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    dfs(1,1,a[n][m]);
    printf("%d",ans);
    return 0;
}