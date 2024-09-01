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
int n, m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    BinaryIndexTree<int> x(new int[n + 5], n), y(new int[n + 5], n);
    while (m--)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
            x.update(l, 1), y.update(r, 1);
        else
            printf("%d\n", x.query(r) - y.query(l - 1));
    }
    return 0;
}