#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005], helper[1000005], n;
ll ans;
void mergesort(int L, int R)
{
    if (L >= R)
        return;
    int mid = L + R >> 1;
    mergesort(L, mid), mergesort(mid + 1, R);
    int l = L, r = mid + 1, pos = 0;
    while (l <= mid || r <= R)
    {
        if (r > R || (l <= mid && a[l] <= a[r]))
            helper[++pos] = a[l++];
        else
        {
            ans += (mid - l + 1);
            helper[++pos] = a[r++];
        }
    }
    for (int i = L; i <= R; i++)
        a[i] = helper[i - L + 1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    mergesort(1, n);
    printf("%lld", ans);
    return 0;
}