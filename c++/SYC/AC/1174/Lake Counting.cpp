#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m, ans;
char a[105][105];
bool f[105][105];
int fx_8[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
void dfs(int x, int y)
{
    f[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + fx_8[i][0], ty = y + fx_8[i][1];
        if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty]=='.' || f[tx][ty]==1)
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
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)  
            if (a[i][j]=='W'&&!f[i][j])
                dfs(i,j),ans++;
    printf("%d",ans);
    return 0;
}