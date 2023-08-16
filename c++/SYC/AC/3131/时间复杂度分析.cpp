#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, m, n, t;
void t1(ll n, ll m)
{
    ll cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cnt *= i;
        if (cnt > m)
        {
            printf("TLE\n");
            return;
        }
    }
    printf("AC\n");
}
void t2(ll n, ll m)
{
    ll cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cnt *= 2;
        if (cnt > m)
        {
            printf("TLE\n");
            return;
        }
    }
    printf("AC\n");
}
void t3(ll n, ll m)
{
    ll cnt = 1;
    for (int i = 1; i <= 4; i++)
    {
        cnt *= n;
        if (cnt > m)
        {
            printf("TLE\n");
            return;
        }
    }
    printf("AC\n");
}
void t4(ll n, ll m)
{
    ll cnt = 1;
    for (int i = 1; i <= 3; i++)
    {
        cnt *= n;
        if (cnt > m)
        {
            printf("TLE\n");
            return;
        }
    }
    printf("AC\n");
}
void t5(ll n, ll m)
{
    ll cnt = 1;
    for (int i = 1; i <= 2; i++)
    {
        cnt *= n;
        if (cnt > m)
        {
            printf("TLE\n");
            return;
        }
    }
    printf("AC\n");
}
void t6(ll n, ll m)
{
    if (n > m)
    {
        printf("TLE\n");
        return;
    }
    printf("AC\n");
}
void t7(ll n, ll m)
{
    if (n > m || n * log2(n) > m)
    {
        printf("TLE\n");
        return;
    }
    printf("AC\n");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &m, &n, &t);
        if (t == 1)
            t1(n, m);
        if (t == 2)
            t2(n, m);
        if (t == 3)
            t3(n, m);
        if (t == 4)
            t4(n, m);
        if (t == 5)
            t5(n, m);
        if (t == 6)
            t6(n, m);
        if (t == 7)
            t7(n, m);
    }
    return 0;
}