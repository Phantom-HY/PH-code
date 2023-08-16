#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b, ll MOD)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ans;
}
int a,b,m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>a>>b>>m;
    cout << qpow(a,b,m);
    return 0;
}