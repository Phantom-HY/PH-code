#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, ans;
char a[1005][1005];
bool f[1005][1005];
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    f[x][y] = 1;
    bool flag = 1;
    while (q.size())
    {
        auto s = q.front();
        q.pop();
        bool fl = 0;
        // printf("%d %d\n",s.x,s.y);
        for (int i = 0; i < 4; i++)
        {
            int tx = s.x + fx_4[i][0], ty = s.y + fx_4[i][1];
            if (tx < 1 || ty < 1 || tx > n || ty > n || f[tx][ty])
                continue;
            if (a[tx][ty] == '.')
            {
                fl = 1;
                continue;
            }
            f[tx][ty] = 1;
            q.push({tx, ty});
        }
        flag &= fl;
    }
    return flag;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == '#' && !f[i][j])
                ans += bfs(i, j);
    printf("%d", ans);
    return 0;
}