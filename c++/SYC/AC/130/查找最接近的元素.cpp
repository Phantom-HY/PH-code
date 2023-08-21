#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x;
int a[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &x);
        auto i = lower_bound(a + 1, a + 1 + n, x) - a;
        if (i == 1 + n)
        {
            printf("%d\n", a[n]);
        }
        else if (i == 1)
        {
            printf("%d\n", a[1]);
        }
        else
        {
            if (abs(a[i] - x) < abs(a[i - 1] - x))
                printf("%d\n", a[i]);
            else
                printf("%d\n", a[i - 1]);
        }
    }
    return 0;
}