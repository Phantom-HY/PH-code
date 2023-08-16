#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], n, q, x;
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
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &x);
        int i = lower_bound(a + 1, a + 1 + n, x) - a;
        if (abs(x - a[i]) < abs(x - a[i - 1]))
            printf("%d\n", abs(x - a[i]));
        else
            printf("%d\n", abs(x - a[i - 1]));
    }
    return 0;
}