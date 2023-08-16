#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
int a[1005][1005];
int x,y,i,j,c;
void fun(int x,int y,int i,int j,int c)
{
    a[x][y]+=c;
    a[x][j+1]-=c;
    a[i+1][y]-=c;
    a[i+1][j+1]+=c;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&c),fun(i,j,i,j,c);
    while (q--)
    {
        scanf("%d%d%d%d%d",&x,&y,&i,&j,&c);
        fun(x,y,i,j,c);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            printf("%d%c",a[i][j]," \n"[j==m]);
        }
    return 0;
}