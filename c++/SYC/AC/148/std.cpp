#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[100005], sum[100005];
int ans_1, ans_2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        ans_1 = max(ans_1, sum[i] - sum[max(i - k, 0)]);
        ans_2 = max(ans_2, sum[min(i + k, n)] - sum[i]);
    }
    printf("%d %d", ans_1, ans_2);
    return 0;
}