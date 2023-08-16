#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
ll ans=1;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (cin>>c)
        ans*=(c-'0'+1),ans%=1000000007;
    printf("%lld", ans);
    return 0;
}