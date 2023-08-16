#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
bool pd(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void bdfs(int x, int step, int k)
{
    // printf("%d %d %d\n",x,step,k);
    if (step == n)
    {
        ans = max(ans, k);
        return;
    }
    if (step > n || x > n)
        return;
    for (int i = x; i <= n; i++)
        if (pd(i))
            bdfs(i + 1, step + i, k + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> n;
    bdfs(2, 0, 0);
    printf("%d", ans);
    return 0;
}