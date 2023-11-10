#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define d2 "%d%d"
#define x first
#define y second
#define pii pair<int, int>
int n, m;
int a[5005][5005];
int i, j, x, y;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf(d2, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf(d2, &x, &y);
        a[x + 1][y + 1] = 1;
    }
    for (int i = 1; i <= 5000; i++)
        for (int j = 1; j <= 5000; j++)
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    while (m--)
    {
        scanf(d2, &i, &j);
        i++, j++;
        scanf(d2, &x, &y);
        x++, y++;
        printf("%d\n", a[x][y] - a[i - 1][y] - a[x][j - 1] + a[i - 1][j - 1]);
    }
    return 0;
}