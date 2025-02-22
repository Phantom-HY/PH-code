#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc scanf
#define pr printf
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
    sc("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        sc("%d", a + i), st[i][0] = a[i];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i + (1 << (p - 1)) <= n; i++)
            st[i][p] = min(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
    while (m--)
    {
        sc("%d%d", &x, &y);
        int q = log2(y - x + 1);
        pr("%d ", min(st[x][q],st[y - (1 << q) + 1][q]));
    }
    return 0;
}