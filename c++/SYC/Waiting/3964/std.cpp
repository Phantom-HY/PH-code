#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[105][105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i][0]);
        for (int j = 1; j <= a[i][0]; j++)
            scanf("%d", &a[i][j]);
    }
    if (n == 1)
    {
        int ans = 0;
        int i = 1, j = a[1][0];
        while (m--)
        {
            if (a[1][i]>a[1][j])
                ans += a[1][i++];
            else
                ans += a[1][j--];
        }
        printf("%d",ans);
    }
    return 0;
}