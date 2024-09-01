#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int st[1000005], p[1000005], pos;
void fun(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            p[++pos] = i;
        for (int j = 1; j <= pos && i * p[j] <= n; j++)
        {
            st[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    fun(n);
    for (int i = 1; i <= pos; i++)
    {
        ll cnt = 0, num = p[i];
        while (n / num != 0)
            cnt += n / num, num *= p[i];
        printf("%lld %lld\n", p[i], cnt);
    }
    return 0;
}