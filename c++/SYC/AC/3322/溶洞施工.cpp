#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, h;
int x;
int a[500005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &l, &h);
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &x);
        if (i % 2 == 1)
        {
            a[1]++;
            a[x + 1]--;
        }
        else
            a[h - x + 1]++;
    }
    int ans = 1, cnt = 0;
    for (int i = 2; i <= h; i++)
    {
        a[i] += a[i - 1];
        if (a[ans] > a[i])
            ans = i;
    }
    for (int i = 1; i <= h; i++)
        cnt += a[i] == a[ans];
    printf("%d %d", a[ans], cnt);
    return 0;
}