#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k, l, h[100005], s[100005], c[5005], d[5005], ma, mb, maxx;
ll ans_Max, ans_Min, e[100005], f[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &k, &l);
    for (int i = 1; i <= k; i++)
        scanf("%d", h + i), c[h[i]]++, ma = max(ma, h[i]);
    sort(h + 1, h + 1 + k);
    for (int i = 1; i <= l; i++)
        scanf("%d", s + i), d[s[i]]++, mb = max(mb, s[i]);
    sort(s + 1, s + 1 + l);
    if (ma != mb)
        printf("-1"), exit(0);
    maxx = max(ma, mb);
    for (int i = 1; i <= maxx; i++)
        ans_Min += max(c[i], d[i]) * i;
    s[l + 1] = INT_MAX;
    for (int i = 1; i <= k; i++)
        e[i] = e[i - 1] + h[i];
    for (int i = 1; i <= l; i++)
        f[i] = f[i - 1] + s[i];
    int j = 1;
    for (int i = 1; i <= k; i++)
    {
        while (j <= l + 1 && s[j] <= h[i])
            j++;
        ans_Max += f[j - 1] + (l - j + 1) * h[i];
    }
    printf("%lld %lld", ans_Min, ans_Max);
    return 0;
}