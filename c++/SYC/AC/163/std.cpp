#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 10000;
int s, n;
int dp[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &s, &n);
    dp[1] = 1;
    for (int i = 2; i <= s; i++)
        for (int j = i - 1; j >= i - n && j >= 1; j--)
            dp[i] += dp[j], dp[i] %= mod;
    printf("%d\n", dp[s]);
    return 0;
}