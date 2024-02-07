#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int a[55][105][105];
void fun()
{
    for (int x = 1; x <= 50; x++)
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                a[x][i][j] += a[x][i - 1][j] + a[x][i][j - 1] - a[x][i - 1][j - 1];
}
int x, y, c;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &c);
        a[c][x][y]++;
    }
    fun();
    int ax, ay, bx, by;
    while (q--)
    {
        scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &c);
        printf("%d\n", a[c][bx][by] - a[c][bx][ay - 1] - a[c][ax - 1][by] + a[c][ax - 1][ay - 1]);
    }
    return 0;
}