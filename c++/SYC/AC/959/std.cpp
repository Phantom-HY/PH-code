#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
struct node
{
    int l, r, id;
    bool operator<(const node i) const
    {
        return l < i.l;
    }
} a[400005];
int f[400005][25];
int ans[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].l, &a[i].r);
        if (a[i].r < a[i].l)
            a[i].r += m;
        a[i + n].l = a[i].l + m;
        a[i + n].r = a[i].r + m;
        a[i].id = i;
        a[i + n].id = i + n;
    }
    sort(a + 1, a + 1 + 2 * n);
    // for (int i = 1; i <= 2 * n; i++)
    //     printf("%d %d\n", a[i].l, a[i].r);
    for (int i = 1; i <= 2 * n; i++)
    {
        int l = i + 1, r = 2 * n;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid].l >= a[i].l && a[mid].l <= a[i].r)
                f[i][0] = mid, l = mid + 1;
            else
                r = mid - 1;
        }
    }
    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= 2 * n; i++)
            f[i][k] = f[f[i][k - 1]][k - 1];
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int k = 20; k >= 0; k--)
            if (f[pos][k] && a[f[pos][k]].r < a[i].l + m)
                ans[a[i].id] += (1 << k), pos = f[pos][k];
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i] + 2);
    return 0;
}