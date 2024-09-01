#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t;
int m[2][2];
int b[1000005], a[10000005], dp[10000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    m[1][0] = 1;
    m[0][0] = 2;
    m[1][1] = 2;
    m[0][1] = 3;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            b[i] = m[x][y];
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            a[i] = b[x];
        }
        int cnt = 0;
        memset(dp, 1, sizeof dp);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (a[i] >= a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
        printf("%d\n", n - dp[n]);
    }
    // upper_bound()
    return 0;
}
