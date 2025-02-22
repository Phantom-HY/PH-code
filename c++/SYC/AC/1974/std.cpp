#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int r[1000005], a[1000005];
int sta[1000005], h, e;
int ans;
int k[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &r[1]);
    for (int i = 2; i <= n; i++)
        r[i] = (r[i - 1] * 6807 + 2831) % 201701;
    for (int i = 1; i <= n; i++)
        a[i] = r[i] % 10;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= a[i]; j++)
    //         printf("*");
    //     puts("");
    // }
    sta[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= sta[e])
        {
            int l = 0;
            int H = min(sta[h], a[i]);
            while (h <= e && sta[e] <= a[i])
            {
                l += k[e];
                ans += k[e] * max(H - sta[e], 0);
                // printf("%d %d %d %d %d\n", i, e, k[e], H - sta[e], ans);
                e--;
            }
            sta[++e] = a[i], k[e] = l + 1;
        }
        else
            sta[++e] = a[i], k[e] = 1;
    }
    printf("%d", ans);
    return 0;
}