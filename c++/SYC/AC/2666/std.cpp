#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int s[1005][1005];
int col[1005];
bool vis[1005];
int sel[1005];
void paint(int u, int x)
{
    col[u] = x;
    for (int i = 1; i <= n; i++)
        if (s[u][i] && !col[i])
            paint(i, 3 - x);
}
bool match(int u)
{
    for (int i = 1; i <= n; i++)
        if (s[u][i] && !vis[i])
        {
            vis[i] = 1;
            if (!sel[i] || match(sel[i]))
            {
                sel[i] = u;
                return 1;
            }
        }
    return 0;
}
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u++, v++;
        s[u][v] = 1;
        s[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!col[i])
            paint(i, 1);
    for (int i = 1; i <= n; i++)
    {
        if (col[i] != 1)
            continue;
        memset(vis, 0, sizeof(vis));
        ans += match(i);
    }
    printf("%d\n", n - ans);
    return 0;
}