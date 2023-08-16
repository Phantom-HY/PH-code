#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[1005][1005], ans[1005], f[1005][1005], k;
void dfs(int x, int y, int sz)
{
    if (x < 1 || x > n || y < 1 || y > n || f[x][y] != 0 || a[x][y] != 0)
        return;
    f[x][y] = sz;
    ans[sz]++;
    //printf("%d %d %d %d\n",x,y,sz,ans[sz]);
    dfs(x - 1, y, sz);
    dfs(x + 1, y, sz);
    dfs(x, y - 1, sz);
    dfs(x, y + 1, sz);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 0 && f[i][j] == 0)
                dfs(i, j, ++k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 0)
                printf("%d%c",ans[f[i][j]]," \n"[j==m]);
            else 
                printf("%d%c",ans[f[i+1][j]]+ans[f[i-1][j]]+ans[f[i][j+1]]+ans[f[i][j-1]]+1," \n"[j==m]);
    return 0;
}