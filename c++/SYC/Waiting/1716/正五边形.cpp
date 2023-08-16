#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, a[25], num[15];
bool dfs(int x, int cnt)
{
    if (x == n + 1)
    {
        return 1;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (num[i] + a[x] <= cnt)
        {
            num[i] += a[x];
            if (dfs(x + 1, cnt))
                return 1;
            num[i] -= a[x];
        }
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        sizeof(num,0,sizeof num);
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i), cnt += a[i];
        if (cnt % 5 != 0)
            puts("No");
        else
        {
            sort(a+1,a+1+n);
            puts(dfs(1, cnt / 5) ? "Yes" : "No");
        }
    }
    return 0;
}