#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m, a[105][105], ans;
bool f[105][105];
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
void dfs(int x, int y)
{
    // printf("-%d %d\n",x,y);
    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + fx_4[i][0], ty = y + fx_4[i][1];
        // printf("(%d %d)-<%d %d> %d{%d %d}\n",x,y,tx,ty,i,fx_4[i][0],fx_4[i][1]);
        if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty]==0 || f[tx][ty]==1)
            continue;
        dfs(tx,ty);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)  
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)  
            if (a[i][j]&&!f[i][j])
                dfs(i,j),ans++;
    printf("%d",ans);
    return 0;
}