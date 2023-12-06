#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll lowbit(ll x)
{
    return x & (-x);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        ll a;
        cin >> a;
        puts(a == lowbit(a) ? "1" : "0");
    }
    return 0;
}