#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], helper[100005], n;
ll ans;
int mergesort(int L, int R)
{
    if (L >= R)
        return a[L];
    int mid = L + R >> 1;
    int cnt_1=mergesort(L, mid), cnt_2=mergesort(mid + 1, R),cnt=cnt_1+cnt_2;
    int l = L, r = mid + 1, pos = 0;
    while (l <= mid || r <= R)
    {
        // printf("%d-%d %d %d %lld\n",L,R,cnt_1,cnt_2,ans);
        if (r > R || (l <= mid && a[l] > a[r]))
            helper[++pos] = a[l++],cnt_1-=a[l-1];
        else
        {
            helper[++pos] = a[r++];
            ans+=cnt_1,cnt_2-=a[r-1];
        }
    }
    for (int i = L; i <= R; i++)
        a[i] = helper[i - L + 1];
    return cnt;
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