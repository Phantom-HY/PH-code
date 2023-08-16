#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, k;
char a[55][55];
int ans(int x, int y, int cnt, int fx)
{
    // printf("%d %d %d %d\n", x, y, cnt, fx);
    if (cnt < 0)
        return 0;
    if (x < 0 || y < 0 || x > n || y > n || a[x][y] != '.')
        return 0;
    // if ((x == n && fx == 1) || (y == n && fx == 2))
    //     return 1;
    if (x==n&&y==n)
        return 1;
    if ((x != n && cnt == 0) && (y != n && cnt == 0))
        return 0;
    if (fx == 1)
        return ans(x, y + 1, cnt, fx) + ans(x + 1, y, cnt - 1, 2);
    return ans(x + 1, y, cnt, fx) + ans(x, y + 1, cnt - 1, 1);
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
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        printf("%d\n", ans(1, 2, k, 1) + ans(2, 1, k, 2));
    }
    return 0;
}