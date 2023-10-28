#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[10000005];
ll sum[10000005];
int ans = 1e9;
bool flag = 0;
bool check(int len)
{
    for (int i = 1; i + len - 1 <= n; i++)
        if (sum[i + len - 1] - sum[i - 1] >= k)
            return 1;
    return 0;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i], flag |= a[i] < 0;
    if (!flag)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%d\n", ans == 0 ? -1 : ans);
        exit(0);
    }
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            if (sum[r] - sum[l - 1] >= k)
                ans = min(ans, r - l + 1);
    printf("%d", ans == 0 ? -1 : ans);
    return 0;
}