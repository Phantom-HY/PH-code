#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
ll a[10], r[10] = {0, 2, 3};
ll CRT()
{
    ll n = 1, ans = 0;
    for (int i = 1; i <= 2; i++)
        n = n * r[i];
    for (int i = 1; i <= 2; i++)
    {
        ll m = n / r[i], b, y;
        exgcd(m, r[i], b, y);
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> T;
    cout << endl;
    while (T--)
    {
        cout << "? 2" << endl;
        cin >> a[1];
        if (a[1] == -1)
            break;
        cout << endl;
        cout << "? 3" << endl;
        cin >> a[2];
        if (a[2] == -1)
            break;
        cout << endl;
        cout << "! " << CRT() << endl;
    }
    return 0;
}