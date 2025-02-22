#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int n, k;
pair<int, int> a[105];
int dp[105][105][105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n);
    memset(dp, 0x3f, sizeof dp);
    int s = n - k;
    for (int i = 1; i <= n; i++)
    {
        
    }
    return 0;
}