#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[105], ans, t;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    scanf("%d", &t);
    for (int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                sum += a[j];
        if (sum == t)
        {
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1)
                    printf("%d ", a[j]);
            puts("");
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}