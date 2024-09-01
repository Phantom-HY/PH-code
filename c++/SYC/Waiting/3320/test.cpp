#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int p;
int cnt[1000005];
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        cnt[p]++;
    }
    for (int i = 1; i <= m; i++)
        ans += cnt[i] - (cnt[i] % 3), cnt[i] %= 3;
    return 0;
}