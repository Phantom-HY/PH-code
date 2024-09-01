#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
char str[100005];
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
ll fun(int l, int r)
{
    ll ans = 0,s = 1;
    for (int i = r-1; i >= l-1; i--,s*=k,s%=998244353)
        ans += (str[i] - '0')*s,ans%=998244353;
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n >> m >> k >> str;
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            str[a - 1] = b+'0';
        if (op == 2)
            sort(str + a - 1, str + b);
        if (op == 3)
            sort(str + a - 1, str + b,greater<char>());
        if (op == 4)
            cout << fun(a,b) << '\n';
        // cout << str <<'\n';
    }
    return 0;
}