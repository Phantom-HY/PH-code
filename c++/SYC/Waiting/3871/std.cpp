#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll yh[105][105];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    for (int i = 0; i <= 20; i++)
        yh[i][0] = 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= i; j++)
            yh[i][j] = yh[i - 1][j] + yh[i - 1][j - 1];
    scanf("%d", &n);
    ll ans = yh[n][1];
    for (int i = 2; i < n; i++)
        ans = __gcd(ans, yh[n][i]);
    printf("%lld", ans);
    return 0;
}