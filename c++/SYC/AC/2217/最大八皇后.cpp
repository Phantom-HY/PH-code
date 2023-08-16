#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans, h[15], a[15][15];
bool l[15], zd[30], xd[30];
bool check(int x, int y)
{
    if (l[y])
        return 0;
    if (zd[x - y + 8])
        return 0;
    if (xd[x + y])
        return 0;
    return 1;
}
void dfs(int x)
{
    if (x == 8 + 1)
    {
        int cnt = 0;
        for (int i = 1; i <= 8; i++)
            cnt += a[i][h[i]];
        ans = max(ans, cnt);
        return;
    }
    for (int i = 1; i <= 8; i++)
        if (check(x, i))
        {
            h[x] = i;
            l[i] = 1;
            zd[x - i + 8] = 1;
            xd[x + i] = 1;
            dfs(x + 1);
            l[i] = 0;
            zd[x - i + 8] = 0;
            xd[x + i] = 0;
        }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            scanf("%d", &a[i][j]);
    dfs(1);
    printf("%d", ans);
    return 0;
}