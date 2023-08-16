#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char a[505][505];
int fx_4[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
bool t[505][505];
int sx,sy;
struct pi
{
    int x, y, cnt;
};
bool check(int x, int y)
{
    if (x<1||y<1||x>n||y>m||t[x][y])return 0;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + fx_4[i][0], ty = y + fx_4[i][1];
        if (a[tx][ty] == '#')
            return 0;
    }
    return 1;
}
void bfs(int x, int y)
{
    queue<pi> q;
    q.push({x, y, 0});
    t[x][y]=1;
    while (q.size())
    {
        auto f = q.front();
        q.pop();
        if (a[f.x][f.y] == 'T')
        {
            printf("%d", f.cnt);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = f.x + fx_4[i][0], ty = f.y + fx_4[i][1];
            if (check(tx,ty))
                q.push({tx,ty,f.cnt+1}),t[tx][ty]=1;
        }
    }
    printf("IMPOSSIBLE");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S')sx=i,sy=j;
        }
    bfs(sx,sy);
    return 0;
}