#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
int len[10005];
int a[10005][10005];
int ans[10005][10005];
vector<int> L, R, lc, lr;
bool check()
{
    // printf("----------------\n");
    for (int i = 0; i < R.size(); i++)
    {
        if (lc[i] != lr[i])
            return false;
    }
    return true;
}
void dfs(int x, int y, int l, int r)
{
    if (x == m + 1)
    {
        lc = L;
        lr = R;
        sort(lc.begin(), lc.end());
        sort(lr.begin(), lr.end());
        if (check())
        {
            printf("YES\n");
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= len[i]; j++)
                    printf("%c", ans[i][j]);
                printf("\n");
            }
            exit(0);
        }
        return;
    }
    if (y == len[x] + 1)
    {
        if (l == r)
        {
            dfs(x + 1, 1, 0, 0);
            return;
        }
        else
            return;
    }
    L.push_back(a[x][y]);
    ans[x][y] = 'L';
    dfs(x, y + 1, l + 1, r);
    L.pop_back();
    R.push_back(a[x][y]);
    ans[x][y] = 'R';
    dfs(x, y + 1, l, r + 1);
    R.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &len[i]);
        for (int j = 1; j <= len[i]; j++)
            scanf("%d", &a[i][j]);
    }
    dfs(1, 1, 0, 0);
    printf("NO\n");
    return 0;
}