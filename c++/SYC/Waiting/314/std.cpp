#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];
int fun(int l, int r)
{
    int max_1 = 0, max_2 = 0;
    for (int i = l; i <= r; i++)
        if (a[i] > a[max_2])
            max_2 = i;
    for (int i = l; i <= r; i++)
        if (i != max_2 && a[i] > a[max_1])
            max_1 = i;
    return a[max_1];
}
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int l = 1; l < n; l++)
        for (int r = l + 1; r <= n; r++)
            ans += fun(l, r);
    printf("%d", ans);
    return 0;
}