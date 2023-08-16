#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[100005], len, to[100005], t = 1, e = 1, m, n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (cin >> cnt[++len])
    {
        if (cnt[len] < cnt[t])
            t = len;
        if (cnt[len] > cnt[e])
            e = len;
        to[cnt[len]]++;
    }
    for (int i = cnt[t]; i <= cnt[e]; i++)
        if (to[i] == 2)
            n = i;
        else if (to[i] == 0)
            m = i;
    printf("%d %d", m, n);
    return 0;
}