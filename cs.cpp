#include<bits/stdc++.h>
using namespace std;
set<int>s1={1,2,3};
set<int>s2={3,1,1};
map<int,int>a;
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
    cout << (s1 == s2) ;
    return 0;
}