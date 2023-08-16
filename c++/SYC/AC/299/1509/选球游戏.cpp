#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[25], ans[25];
void dfs(int step, int x)
{
    if (step == n)
    {
        for (int i = 1; i <= k; i++)
            printf("%d", ans[i]);
        puts("");
        return;
    }
    if (x == k + 1)
        return;
    for (int i=0;i<=n-step&&i<=a[x];i++)
    {
        ans[x]=i;
        dfs(step+i,x+1);
        ans[x]=0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= k; i++)
        scanf("%d", a + i);
    dfs(0,1);
    return 0;
}