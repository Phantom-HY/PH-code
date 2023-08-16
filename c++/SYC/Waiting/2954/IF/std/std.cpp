#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int w[100005], c[100005];
int dp[200005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", w + i, c + i);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    printf("%d\n", dp[m]);
    return 0;
}