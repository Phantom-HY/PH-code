#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[10005];
int dp[10005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
    printf("%d\n", *max_element(dp + 1, dp + 1 + n));
    return 0;
}