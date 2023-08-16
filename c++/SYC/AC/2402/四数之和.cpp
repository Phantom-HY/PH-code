#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m, a[5005], b[5005], c[5005], d[5005], len[5], ab[20000005],ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &m);
    scanf("%lld", &len[1]);
    for (int i = 1; i <= len[1]; i++)
        scanf("%lld", a + i);
    scanf("%lld", &len[2]);
    for (int i = 1; i <= len[2]; i++)
        scanf("%lld", b + i);
    scanf("%lld", &len[3]);
    for (int i = 1; i <= len[3]; i++)
        scanf("%lld", c + i);
    scanf("%lld", &len[4]);
    for (int i = 1; i <= len[4]; i++)
        scanf("%lld", d + i);
    for (int i=1;i<=len[1];i++)
        for (int j=1;j<=len[2];j++)
            ab[a[i]+b[j]]++;
    for (int i = 1; i <= len[3]; i++)
        for (int j = 1; j <= len[4]; j++)
            if (m-c[i]-d[j]<=0)continue;
            else ans+=ab[m-c[i]-d[j]];
    printf("%lld",ans);
    return 0;
}