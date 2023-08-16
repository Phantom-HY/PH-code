#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int n;
int a[100005];
ll sum[100005];
int ans;
int s(int l, int r)
{
    int x = l;
    while (l < r - 1)
    {
        ll mid = (l + r) >> 1;
        if (sum[mid] - sum[x] >= sum[x])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}
int h(int l, int r, int x)
{
    while (l < r - 1)
    {
        ll mid = (l + r) >> 1;
        if (sum[mid] - sum[x] <= sum[n] - sum[mid])
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i < n - 1; i++)
    {
        // for (int mid = l + 1; mid < n; mid++)
        // {
        // if (sum[l]<=sum[mid]-sum[l]&&sum[mid]-sum[l]<=sum[n]-sum[mid])
        //     ans++,ans%=mod;
        int cnt = s(i, n);
        if (sum[cnt] - sum[i] < sum[i])
            continue;
        int x = h(cnt, n + 1, i);
        if (sum[x] - sum[i] > sum[n] - sum[x])
            continue;
        ans = (ans + x - cnt + 1) % mod;
        // }
    }
    printf("%d", ans);
    return 0;
}