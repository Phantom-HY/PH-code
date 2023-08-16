#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, m,ans;
int x[1000005];
int z[100005][10];
int cg(int i, int j, int y)
{
    if (i <= 0 && j <= 0 && y <= 0)
        return 0;
    return (i - 1) * (b * c) + j * y;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &a, &b, &c, &m);
    for (int i = 1; i <= a * b * c; i++)
        scanf("%d", &x[i]);
    for (int u = 1; u <= m; u++)
    {
        for (int j = 1; j <= 7; j++)
            scanf("%d", &z[u][j]);
        for (int i=z[u][1];i<=z[u][2];i++)
            for (int j=z[u][3];j<=z[u][4];j++)
                for (int y=z[u][5];y<=z[u][6];y++)
                {
                    x[cg(i,j,y)]-=z[i][7];
                    if (x[cg(i,j,y)]<0&&ans==0)
                        ans=u;
                }
    }
    printf("%d", ans);
    return 0;
}