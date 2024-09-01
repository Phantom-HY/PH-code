#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t;
ll a[100005];
ll mod = 1000000007;
struct Matrix
{
    ll data[31][31], r, c;
    Matrix() { memset(data, 0, sizeof data); }
    Matrix(int _r, int _c) : r(_r), c(_c) { memset(data, 0, sizeof data); }

    Matrix operator+(const Matrix &t) const
    {
        Matrix res;
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                res.data[i][j] = (data[i][j] + t.data[i][j]) % mod;
        return res;
    }
    Matrix operator*(const Matrix &t) const
    {
        Matrix res;
        res.r = r, res.c = t.c;
        for (int i = 1; i <= r; i++)
            for (int k = 1; k <= t.r; k++)
            {
                ll tmp = data[i][k];
                for (int j = 1; j <= t.c; j++)
                    res.data[i][j] = (res.data[i][j] + tmp * t.data[k][j] % mod) % mod;
            }
        return res;
    }
    Matrix operator^(ll x) const
    {
        Matrix res(r, r), base(r, r);
        for (int i = 1; i <= r; i++)
            res.data[i][i] = 1;
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                base.data[i][j] = data[i][j] % mod;
        while (x)
        {
            if (x & 1)
                res = res * base;
            base = base * base;
            x >>= 1;
        }
        return res;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        ll ans = 0;
        scanf("%d%lld%lld", &n, a + 1, a + 2);
        if (n <= 45)
        {
            for (int i = 3; i <= n; i++)
                a[i] = a[i - 1] + a[i - 2], a[i] %= mod;
            for (int i = 1; i <= n; i++)
                if (a[i] % 2 == 0)
                    ans += a[i], ans %= mod;
            printf("%lld\n", ans);
        }
        if (a[1] % 2 == 0 && a[2] % 2 == 0)

        {
        }
    }
    return 0;
}