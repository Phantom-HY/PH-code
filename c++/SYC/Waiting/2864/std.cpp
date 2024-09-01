#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005];
double f[100005];
int n, m, v, e;
int dis[1005][1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &v, &e);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (int i = 1; i <= n; i++)
        scanf("%lf", f + i);
    for (int i = 1; i <= e; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        dis[x][y] = dis[y][x] = w;
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    double ans = 0;
    for (int i = 2;i<=n;i++)
        ans+=dis[a[i-1]][a[i]];
    printf("%.2lf",ans);
    return 0;
}