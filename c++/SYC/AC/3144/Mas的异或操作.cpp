#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, x, a[100005], cnt1[1025], cnt[1025], h, m = 1005;
void fun()
{
    int pos = 1;
    for (int i = 0; i <= 1024; i++)
    {
        if (cnt[i] != 0)
        {    
            if (pos == 1)
                cnt1[i ^ x] += ((cnt[i] + 1) >> 1), cnt1[i] -= ((cnt[i] + 1) >> 1);
            else
                cnt1[i ^ x] += (cnt[i] >> 1), cnt1[i] -= (cnt[i] >> 1);
            pos += cnt[i];
            pos %= 2;
        }
    }
    for (int i = 0; i <= 1024; i++)
        cnt[i] = cnt1[i];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), cnt[a[i]]++, cnt1[a[i]]++;
    while (k--)
    {
        fun();
    }
    for (int i = 0; i <= 1024; i++)
        if (cnt[i] != 0)
            h = max(h, i), m = min(m, i);
    printf("%d %d", h, m);
    return 0;
}