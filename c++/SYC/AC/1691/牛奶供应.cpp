#include <bits/stdc++.h>
using namespace std;
int n, m, p, r, ans, a[100001], idx = 1;
int main()
{
#ifndef ONL INE JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", a + i, &r);
        while (r > 0 && idx <= i)
        {
            if (i - idx > m)
                idx++;
            else if (r >= a[idx])
            {
                ans += a[idx];
                r -= a[idx++];
            }
            else
            {
                ans += r, a[idx] -= r;
                r=0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}