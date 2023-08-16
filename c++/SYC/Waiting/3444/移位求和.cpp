#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
int x[9];
ll ans[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld%d%d%d%d", &T, x + 1, x + 2, x + 3, x + 4);
    x[5] = x[1], x[6] = x[2], x[7] = x[3], x[8] = x[4];
    ans[1] = ans[2] = ans[3] = ans[4] = (x[1] + x[2] + x[3] + x[4]) * (T / 4);
    if (T % 4 != 0)
    {
        ans[1] += x[0 + T % 4];
        ans[2] += x[1 + T % 4];
        ans[3] += x[2 + T % 4];
        ans[4] += x[3 + T % 4];
    }
    ans[3]+=ans[4]/10,ans[4]%=10;
    ans[2]+=ans[3]/10,ans[3]%=10;
    ans[1]+=ans[2]/10,ans[2]%=10;
    printf("%lld%lld%lld%lld\n",ans[1],ans[2],ans[3],ans[4]);
    return 0;
}