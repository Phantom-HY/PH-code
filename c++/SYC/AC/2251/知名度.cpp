#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> f[4005];
map<pair<int,int>,bool>g;
int n, m;
int x, y;
int v[4005];
int ans = 1e9;
bool vis[4005];
void dfs(int x, int st, int cnt, int num)
{
    if (cnt >= ans)
        return;
    if (x == st && num == 3)
    {
        ans = min(ans, cnt);
        return;
    }
    if (x == st && num != 0)
        return;
    if (num > 3)
        return;
    for (int i = 0; i < f[x].size(); i++)
    {
        int y = f[x][i];
        if (!vis[y])
            vis[y] = 1,
            dfs(y, st, cnt + v[y], num + 1),
            vis[y] = 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        if (x>y)
            swap(x, y);
        pair<int,int> j;
        j={x,y};
        if (g[j]==1)
            continue;
        g[j]=1;
        f[x].push_back(y);
        v[x]++;
        f[y].push_back(x);
        v[y]++;
    }
    for (int i = 1; i <= n; i++)
        dfs(i, i, 0, 0);
    printf("%d\n", ans == 1e9 ? -1 : ans);
    return 0;
}