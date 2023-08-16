#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int k[25], len;
vector<int> ans_1, ans_2;
unordered_map<int,vector<int>>m;
void f()
{
    while (a)
    {
        k[++len] = a % 10;
        a /= 10;
    }
}
// 取相反数
ll fx(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
void bdfs(ll x, ll cnt, ll step_1, ll step_2, ll c)
{
    
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &a);
    f();
    return 0;
}