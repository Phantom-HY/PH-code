#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
ll sum[100005] = {1};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        flag += a[i] == 0;
        sum[i] = sum[i - 1] * a[i];
    }
    ll cnt = 1;
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i - 1] * cnt;
        cnt *= a[i];
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", sum[i]);
    return 0;
}