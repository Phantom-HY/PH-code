#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// SegTreeLazyRangAdd
template <typename T>
class SegTree
{
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    vector<T> tree, tag;
    T *arr;
    int n;
    void pushup(int p)
    {
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }
    void add(int p, int l, int r, T val)
    {
        tag[p] = val;
        tree[p] = val;
    }
    void pushdown(int p, int l, int r)
    {
        if (tag[p])
        {
            int mid = (l + r) >> 1;
            add(ls(p), l, mid, tag[p]);
            add(rs(p), mid + 1, r, tag[p]);
            tag[p] = 0;
        }
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            tree[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        tree[p] = tree[ls(p)] | tree[rs(p)];
    }
    T range_sum(int p, int l, int r, int L, int R)
    {
        if (L > r || R < l)
            return 0;
        if (L <= l && r <= R)
            return tree[p];
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        T sum = 0;
        if (L <= mid)
            sum |= range_sum(ls(p), l, mid, L, R);
        if (R > mid)
            sum |= range_sum(rs(p), mid + 1, r, L, R);
        return sum;
    }
    void range_add(int p, int l, int r, int L, int R, T val)
    {
        if (L > r || R < l)
            return;
        if (L <= l && r <= R)
        {
            add(p, l, r, val);
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid)
            range_add(ls(p), l, mid, L, R, val);
        if (R > mid)
            range_add(rs(p), mid + 1, r, L, R, val);
        tree[p] = tree[ls(p)] | tree[rs(p)];
    }

public:
    explicit SegTree<T>(T v[], int len)
    {
        n = len, arr = v;
        tree = vector<T>(n << 2 | 1, 0), tag = vector<T>(n << 2 | 1, 0);
        build(1, 1, n);
        arr = NULL;
    }
    void show(int p, int dep = 0)
    {
        if (p > (n << 2) || tree[p] == 0)
            return;
        show(ls(p), dep + 1);
        for (int i = 1; i <= dep; i++)
            printf("\t");
        printf("%d\n", tree[p]);
        show(rs(p), dep + 1);
    }
    T range_sum(int l, int r) { return range_sum(1, 1, n, l, r); }
    void range_add(int l, int r, T val) { range_add(1, 1, n, l, r, val); };
    void node_add(int p, T val) { range_add(1, 1, n, p, p, val); }
};
int fun(int x)
{
    int sum = 0;
    while (x)
    {
        if (x % 2 == 1)
            sum++;
        x /= 2;
    }
    return sum;
}
int l, t, o;
int a[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> l >> t >> o;
    for (int i = 1; i <= l; i++)
        a[i] = 1;
    SegTree<int> tree(a, l);
    while (o--)
    {
        int a, b, x;
        char op;
        cin >> op;
        // puts("-----------------------");
        // tree.show(1);
        // puts("-----------------------");
        if (op == 'C')
        {
            cin >> a >> b >> x;
            tree.range_add(a, b, 1 << (x - 1));
        }
        else
        {
            cin >> a >> b;
            int x = tree.range_sum(a, b);
            printf("%d\n", fun(x));
        }
    }
    return 0;
}