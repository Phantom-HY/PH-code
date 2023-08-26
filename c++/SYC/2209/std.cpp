#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
ll sum[100005], ans;
int id = 1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    int st = 0, ed = 1;
    int m = 2;
    int x = 1;
    while (st != n)
    {
        if (sum[ed] - sum[st] > ans)
        {
            ans = sum[ed] - sum[st];
            id = x;
        }
        st = ed;
        ed += m;
        ed = min(ed, n);
        m *= 2;
        x++;
    }
    printf("%d\n", id);
    return 0;
}