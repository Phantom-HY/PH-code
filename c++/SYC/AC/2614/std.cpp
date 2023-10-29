#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[100005];
int x, y;
int st[100005][25];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int j = 0; j <= 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (j == 0)
                st[i][j] = a[i];
            else
                st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while (m--)
    {
        scanf("%d%d", &x, &y);
        int k = log2(y - x + 1);
        printf("%d\n", __gcd(st[x][k], st[y - (1 << k) + 1][k]));
    }
    return 0;
}