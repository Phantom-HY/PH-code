#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[45];
int ans;
int Get_4(ll x)
{
    x = abs(x);
    int sum = 0;
    while (x != 0)
    {
        if (x % 10 == 4)
            sum++;
        x /= 10;
    }
    return sum;
}
void dfs(int x, ll sum)
{
    if (x == n + 1)
    {
        ans += Get_4(sum);
        return;
    }
    dfs(x + 1, sum + a[x]);
    dfs(x + 1, sum);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}