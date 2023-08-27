#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans[55] = {0, 1};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    for (int i = 2; i <= 50; i++)
        ans[i] = ans[i - 1] + ans[i - 2];
    scanf("%d", &n);
    while (n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", ans[y - x + 1]);
    }
    return 0;
}