#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
string a;
int cnt[1000005];
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
    void update(int i)
    {
        int x = v[i] - v[i - 1];
        int val = (x == 1) ? -1 : 1;
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n >> m >> a;
    a = " " + a + " ";
    for (int i = 1; i <= n; i++)
        cnt[i] = a[i] == a[i + 1];
    BinaryIndexTree<int> BI(cnt, n);
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            if (x != 1 && x != n)
                BI.update(x - 1);
            if (y != 1 && y != n)
                BI.update(y);
        }
        else
        {
            int v = BI.query(y) - BI.query(x - 1);
            if (v == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}