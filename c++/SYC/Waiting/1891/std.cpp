#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x, dis[105][105];
int u, v, w;
int ans[105];
vector<int> cnt[105];
int s[105];
void dfs(int x, int len = 1)
{
    s[len] = x;
    if (len >= 2)
    {
        printf("%d", s[1]);
        for (int i = 2; i <= len; i++)
            printf("->%d", s[i]);
        puts("");
    }
    for (auto &&i : cnt[x])
        dfs(i, len + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    scanf("%d", &x);
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = w;
        if (u == x)
            ans[v] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    if (i == x)
                    {
                        printf("dis[%d][%d] = %d k:%d\n", i, j, dis[i][j], k);
                        ans[j] = k;
                    }
                }
            }
    for (int i = 1; i <= n; i++)
        cnt[ans[i]].push_back(i);
    dfs(x);
    return 0;
}