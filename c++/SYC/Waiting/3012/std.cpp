#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int a[800][800];
int find(int i, int j, int x, int y)
{
    int ans = 1e9;
    for (; i <= x; i++)
        for (; j <= y; j++)
            ans = min(ans, a[i][j]);
    return ans;
}
int ans_m, ans_n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (i * j >= k)
                for (int x = 1; x + i - 1 <= n; x++)
                    for (int y = 1; y + j - 1 <= m; y++)
                    {
                        int cnt = find(x, y, x + i - 1, y + j - 1);
                        if (cnt > ans_m)
                            ans_m = cnt, ans_n = i * j;
                        else if (cnt == ans_m)
                            ans_n = max(ans_n, i * j);
                    }
    }
    printf("%d %d\n", ans_m, ans_n);
    return 0;
}