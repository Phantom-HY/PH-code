#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, m;
int a[10][10], ans;
bool b[10][10];
int fx_8[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
bool check(int x,int y)
{
    if (x<1||x>n||y<1||y<n)
        return 0;
    for (int i=0;i<8;i++)
    {
        int tx=x+fx_8[i][0],ty=y+fx_8[i][1];
        if (b[tx][ty])
            return 0;
    }
    return 1;
}
void dfs(int x, int y,int step)
{
    ans=max(step,ans);
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
    }
    return 0;
}