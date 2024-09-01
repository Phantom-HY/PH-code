#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
int up[100005], down[100005];
int dp[100005][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    up[1] = down[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i - 1])
            up[i] = up[i - 1];
        else
            up[i] = up[i - 1] ^ 1;
        if (a[i] <= a[i - 1])
            down[i] = down[i - 1];
        else
            down[i] = down[i - 1] ^ 1;
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", up[i], i == n ? '\n' : ' ');
    for (int i = 1; i <= n; i++)
        printf("%d%c", down[i], i == n ? '\n' : ' ');
    return 0;
}