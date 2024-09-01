#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int p;
int cnt[1000005];
int ans;
void fun(int x, int sum)
{
    if (x == m + 1)
    {
        ans = max(ans, sum);
        return;
    }
    if (cnt[x] >= 3)
    {
        cnt[x] -= 3;
        fun(x, sum + 3);
        cnt[x] += 3;
    }
    if (cnt[x] && cnt[x + 1] && cnt[x + 2])
    {
        cnt[x]--;
        cnt[x + 1]--;
        cnt[x + 2]--;
        fun(x, sum + 3);
        cnt[x]++;
        cnt[x + 1]++;
        cnt[x + 2]++;
    }
    fun(x + 1, sum);
}
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
    fun(1, 0);
    printf("%d", ans);
    return 0;
}