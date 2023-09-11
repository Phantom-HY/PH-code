#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y, z;
ll dp[2][300005];
char s[300005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d\n", &x, &y, &z);
    scanf("%s", s);
    dp[0][0] = 0;
    dp[1][0] = 0x3f3f3f3f;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'm')
        {
            dp[0][i + 1] = min(dp[0][i] + x, dp[1][i] + y + z);
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + z + x);
            dp[1][i + 1] = min(dp[1][i] + y, dp[0][i] + x + z);
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + z + y);
        }
        else if (s[i] == 'M')
        {
            dp[0][i + 1] = min(dp[0][i] + y, dp[1][i] + x + z);
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + z + y);
            dp[1][i + 1] = min(dp[1][i] + x, dp[0][i] + y + z);
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + z + x);
        }
        // printf("%lld %lld\n", dp[0][i + 1], dp[1][i + 1]);
    }
    printf("%lld\n", min(dp[0][strlen(s)], dp[1][strlen(s)]));
    return 0;
}