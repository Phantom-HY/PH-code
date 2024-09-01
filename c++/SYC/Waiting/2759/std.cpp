#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[205];
ll p[105] = {1};
void init()
{
    for (int i = 1; i <= 13; i++)
        p[i] = p[i - 1] * i;
}
void Get(int len, ll t)
{
    t--;
    // int ans[205];
    // for (int i = 1; i <= len; i++)
    //     ans[i] = i;
    // t--;
    // while (t)
    // {
    //     ll x = 1;
    //     int i = 2;
    //     for (; i <= len && x <= t; i++)
    //         x *= i;
    //     i--;
    //     x /= i;
    //     i--;
    //     i = len - i;
    //     ll num = t / x;
    //     ll ch = ans[i + num];
    //     for (int j = i + num; j > i; j--)
    //         ans[j] = ans[j - 1];
    //     ans[i] = ch;
    //     t %= x;
    // }
    // for (int i = 1; i <= len; i++)
    //     printf("%d ", ans[i]);
    // puts("");
}
void Get_id(int len)
{
    ll ans = 0;
    for (int i = 1; i <= len - 1; i++)
    {
        ll count = 0;
        for (int j = i + 1; j <= len; j++)
            if (a[i] > a[j])
                count++;
        ans += count * p[len - i];
    }
    printf("%lld\n", ans + 1);
}
int n, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    // int id = 1;
    // do
    // {
    //     printf("ID:%d\n", id);
    //     for (int i = 0; i <= 4; i++)
    //         printf("%d ", a[i]);
    //     puts("");
    //     id++;
    // } while (next_permutation(a, a + 5));
    init();
    cin >> n >> k;
    while (k--)
    {
        char op;
        cin >> op;
        if (op == 'P')
        {
            int x;
            cin >> x;
            Get(n, x);
        }
        else
        {
            for (int i = 1; i <= n; i++)
                cin >> a[i];
            Get_id(n);
        }
    }
    return 0;
}