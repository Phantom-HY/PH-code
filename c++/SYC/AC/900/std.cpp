#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// BinaryIndexTree
template <typename T>
class BinaryIndexTree
{
    vector<T> v;
    int len;
    int lowbit(int x)
    {
        return x & -x;
    }

public:
    explicit BinaryIndexTree<T>(T a[], int n)
    {
        v.assign(n + 5, 0);
        len = n;
        for (int i = 1; i <= n; i++)
        {
            v[i] += a[i];
            int j = i + lowbit(i);
            if (j <= n)
                v[j] += v[i];
        }
    }
    void update(int i, T val)
    {
        for (int j = i; j <= len; j += lowbit(j))
            v[j] += val;
    }
    T query(int i)
    {
        T ans = 0;
        for (int j = i; j > 0; j -= lowbit(j))
            ans += v[j];
        return ans;
    }
};
int n, q;
ll a[1000005];
ll d[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - a[i - 1];
    BinaryIndexTree<ll> tree(d, n);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            tree.update(l, x);
            tree.update(r + 1, -x);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", tree.query(x));
        }
    }
    return 0;
}