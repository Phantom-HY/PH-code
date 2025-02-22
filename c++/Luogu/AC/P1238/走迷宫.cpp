#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[15][15];
int sx,sy,ex,ey;
int ans[1005][3];
bool b[15][15],flag;
int fx_4[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
void dfs(int x,int y,int len)
{
    if (x==ex&&y==ey)
    {
        flag=1;
        printf("(%d,%d)",sx,sy);
        for (int i=1;i<=len;i++)
            printf("->(%d,%d)",ans[i][1],ans[i][2]);
        printf("\n");
        return ;
    }
    for (int i=0;i<4;i++)
    {
        int tx=x+fx_4[i][0],ty=y+fx_4[i][1];
        if (tx<1||ty<1||tx>n||ty>m||b[tx][ty]||!a[tx][ty])
            continue;
        ans[len+1][1]=tx,ans[len+1][2]=ty;
        b[tx][ty]=1;
        dfs(tx,ty,len+1);
        b[tx][ty]=0;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    b[sx][sy]=1;
    dfs(sx,sy,0);
    if (!flag)
        printf("-1");
    return 0;
}