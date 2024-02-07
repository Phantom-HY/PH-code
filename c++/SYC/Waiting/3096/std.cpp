#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int k;
int d[6];
int ans;
int N(int x)
{
    int sum_1, sum_2;
    sum_1 = sum_2 = 0;
    int i = x;
    if (i != 1)
        while (i != 2)
            sum_1 += d[--i];
    else
        sum_1 = 1e9;
    i = x;
    while (i != 2)
        sum_2 += d[i = i == 5 ? 1 : i + 1];
    return min(sum_1, sum_2);
}
void dfs(int x, int sum)
{
    if (sum >= ans)
        return;
    if (sum >= k)
    {
        ans = min(ans, N(x) + sum);
        return;
    }
    dfs(x + 1 == 5 ? 1 : x + 1, sum + d[x]);
    if (x != 1)
        dfs(x - 1, sum + d[x - 1]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d%d", &k, &d[1], &d[2], &d[3], &d[4]);
        ans = 1e9;
        dfs(2, 0);
        printf("%d\n", ans);
    }
    return 0;
}