#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int helper[1000005], n;
int ans;
struct noo
{
    int cnt, x;
    bool operator<(const noo t) const
    {
        if (cnt != t.cnt)
            return cnt < t.cnt;
        return x < t.x;
    }
} a[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].cnt), a[i].x = i;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        ans = max(ans, a[i].x - i);
    printf("%d", ans + 1);
    return 0;
}