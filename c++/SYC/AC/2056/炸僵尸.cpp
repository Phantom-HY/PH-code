#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, m, x, y, ans;
char a[1505][1505];
int fx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool p[1505][1505];
void bdfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    p[x][y] = 1;
    while (q.size())
    {
        auto f = q.front();
        q.pop();
        // printf("%d %d\n",f.x,f.y);
        int cnt = 0;
        for (int i = f.x + 1; i <= n && a[i][f.y] != '#'; i++)
            cnt += a[i][f.y] == 'G';
        for (int i = f.x - 1; i >= 1 && a[i][f.y] != '#'; i--)
            cnt += a[i][f.y] == 'G';
        for (int j = f.y + 1; j <= m && a[f.x][j] != '#'; j++)
            cnt += a[f.x][j] == 'G';
        for (int j = f.y - 1; j >= 1 && a[f.x][j] != '#'; j--)
            cnt += a[f.x][j] == 'G';
        ans = max(cnt, ans);
        for (int i = 0; i < 4; i++)
        {
            int tx = f.x + fx[i][0], ty = f.y + fx[i][1];
            // printf("txy %d %d\n",tx,ty);
            if (a[tx][ty] == '.' && p[tx][ty] == 0)
                q.push({tx, ty}), p[tx][ty] = 1;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    bdfs(x, y);
    printf("%d\n", ans);
    return 0;
}