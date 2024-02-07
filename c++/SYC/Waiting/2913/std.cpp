#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll dis[205][205][205];
pair<ll, ll> x[205];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i].first);
        x[i].second = i;
    }
    sort(x + 1, x + n + 1);
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &dis[0][i][j]);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                    dis[k][x[i].second][x[j].second] =
                        min(dis[k - 1][x[i].second][x[j].second],
                            dis[k - 1][x[i].second][x[k].second] + dis[k - 1][x[k].second][x[j].second]);
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                printf("%lld%c", dis[i][j][k], " \n"[k == n]);
            }
    scanf("%d", &m);
    ll u, v, w;
    while (m--)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        int i = 1;
        for (; i <= n; i++)
            if (x[i].first > w)
                break;
        printf("%lld %lld\n", dis[x[i - 1].second][u][v], x[i - 1].second);
    }
    return 0;
}