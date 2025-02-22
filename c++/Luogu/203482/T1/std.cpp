#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
ll W, d;
ll a[200005];
int l, r;
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
        tag[p] += val;
        tree[p] += (r - l + 1) * val;
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
        pushup(p);
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
            sum += range_sum(ls(p), l, mid, L, R);
        if (R > mid)
            sum += range_sum(rs(p), mid + 1, r, L, R);
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
        pushup(p);
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("wxyt4.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%lld", &n, &q, &W);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    SegTree<ll> T(a, n);
    ll all = T.range_sum(1, n);
    while (q--)
    {
        ll w = W;
        scanf("%d%d%lld", &l, &r, &d);
        T.range_add(l, r, d);
        all += d * (r - l + 1);
        ll p = 1, t = 0;
        // printf("!!!!!!!!!!!!%d", t);
        while (w > p * all)
        {
            w -= p * all;
            t++;
            p *= 2;
            // printf("%lld %lld %lld\n", w, all, p);
        }
        // printf("!!!!!!!!!!!!%d", t);
        int L = 1, R = n;
        while (L < R)
        {
            int mid = (L + R) >> 1;
            if (w <= p * T.range_sum(1, mid))
                R = mid;
            else
                L = mid + 1;
        }
        printf("%d\n", t * n + R - 1);
    }
    return 0;
}