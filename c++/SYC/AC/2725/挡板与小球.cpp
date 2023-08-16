#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[205][205];
void fun(int x)
{
    int c=1;
    while (c!=n+1)
    {
        int u=a[c][x];
        x+=u;
        if (x<1||x==m+1||a[c][x]!=u)
        {
            printf("-1\n");
            return ;
        }
        c++;
    }
    printf("%d\n",x-1);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    a[n][0]=1,a[n][m+1]=-1;
    for (int i=1;i<=m;i++)fun(i);
    return 0;
}