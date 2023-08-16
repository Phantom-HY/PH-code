#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> a[200005], b[200005], c[200005];
string s;
int n, a_len, b_len, c_len, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--)
    {
        cin >> s;
        if (s == "push")
        {
            char r;
            int x;
            cin >> r >> x;
            if (r == 'A')
                a[++a_len] = {k++, x};
            if (r == 'B')
                b[++b_len] = {k++, x};
        }
        else if (s == "pop")
        {
            char r;
            cin >> r;
            if (r == 'A')
                if (a_len)
                    printf("%d\n", a[a_len--].second);
                else
                    printf("%d\n", c[c_len--].second);
            if (r == 'B')
                if (b_len)
                    printf("%d\n", b[b_len--].second);
                else
                    printf("%d\n", c[c_len--].second);
        }
        else
        {
            char A, B;
            cin >> A >> B;
            if (A == 'A')
                merge(a + 1, a + 1 + a_len, b + 1, b + 1 + b_len, c + c_len + 1), c_len += a_len + b_len, a_len = 0, b_len = 0;
            else
                merge(a + 1, a + 1 + a_len, b + 1, b + 1 + b_len, c + c_len + 1), c_len += a_len + b_len, a_len = 0, b_len = 0;
        }
    }
    return 0;
}