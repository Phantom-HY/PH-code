#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a, b;
char s[55][55];
const int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int ans = 1e9;
bool vis[55][55];
void dfs(int x, int y, int cnt)
{
    if (cnt >= ans)
        return;
    if (x == n && y == n)
    {
        ans = min(cnt, ans);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + fx_4[i][0], ny = y + fx_4[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > n || vis[nx][ny])
            continue;
        vis[nx][ny] = 1;
        if (s[x][y] == s[nx][ny])
            dfs(nx, ny, cnt + a);
        else
            dfs(nx, ny, cnt + b);
        vis[nx][ny] = 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &a, &b);
    for (int i=1;i<=n;i++)
        scanf("%s", s[i]+1);
    dfs(1,1,0);
    printf("%d\n", ans);
    return 0;
}