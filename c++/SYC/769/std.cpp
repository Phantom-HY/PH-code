#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int s;
int t[5005], c[5005];
int sumt[5005], sumc[5005];
int dp[5005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%d", &s);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", t + i, c + i),
            sumt[i] = sumt[i - 1] + t[i], sumc[i] = sumc[i - 1] + c[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            dp[i] = min(dp[i], dp[j] + sumt[i] * (sumc[i] - sumc[j]) + s * (sumc[n] - sumc[j]));
    printf("%d\n", dp[n]);
    return 0;
}