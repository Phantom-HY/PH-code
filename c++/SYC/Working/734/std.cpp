#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int w[55];
__int128 dp[55][55];
void print(__int128 x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i);
    memset(dp,0x3f,sizeof dp);
    for (int len = 0; len <= 2; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 0;
        }
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
                if (dp[l][r] > dp[l][k] + dp[k + 1][r] + w[l] * w[k] * w[r])
                    dp[l][r] = dp[l][k] + dp[k + 1][r] + w[l] * w[k] * w[r];
        }
    print(dp[1][n]);
    return 0;
}