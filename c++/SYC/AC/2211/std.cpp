#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define d2 "%d%d"
int m, n;
int a[20005], b[20005];
vector<int> v;
int dp[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf(d2, &m, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(d2, &a[i], &b[i]);
        for (int j = 1; j <= b[i]; j++)
            v.push_back(a[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = m; j >= v[i]; j--)
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
    if (dp[m] == 0x3f3f3f3f)
        puts("><"), exit(0);
    printf("%d\n", dp[m]);
    return 0;
}