#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// SegTreeLazyRangAdd
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
struct node
{
    int l, r;
    ll val, tag;
} tree[4000005];
int n, a[1000005];
void pushup(int p)
{
    tree[p].val = tree[ls(p)].val + tree[rs(p)].val;
}
void add(int p, ll val)
{
    tree[p].val += (tree[p].r - tree[p].l + 1) * val;
    tree[p].tag += val;
}
void pushdown(int p)
{
    if (tree[p].tag)
    {
        add(ls(p), tree[p].tag);
        add(rs(p), tree[p].tag);
        tree[p].tag = 0;
    }
}
void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
    {
        tree[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}
ll query(int p, int l, int r)
{
    if (tree[p].l > r || tree[p].r < l)
        return 0;
    if (tree[p].l >= l && tree[p].r <= r)
        return tree[p].val;
    pushdown(p);
    ll ans = 0;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        ans += query(ls(p), l, r);
    if (r > mid)
        ans += query(rs(p), l, r);
    return ans;
}
void update(int p, int l, int r, ll val) // 区间修改
{
    if (l <= tree[p].l && tree[p].r <= r) // 区间被包含
    {
        add(p, val);
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (l <= mid)
        update(ls(p), l, r, val);
    if (r > mid)
        update(rs(p), l, r, val);
    pushup(p);
}
int q;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    build(1, 1, n);
    int op, l, r, x;
    while (q--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &l, &r, &x);
            update(1, l, r, x);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}