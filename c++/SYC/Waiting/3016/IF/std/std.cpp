#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[10000005];
ll sum[10000005];
int ans = 1e9;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            if (sum[r] - sum[l - 1] >= k)
                ans = min(ans, r - l + 1);
    printf("%d", ans == 0 ? -1 : ans);
    return 0;
}