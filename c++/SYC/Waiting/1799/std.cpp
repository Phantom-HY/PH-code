#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char a[100005];
int l, r;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    scanf("%s", a + 1);
    while (m--)
    {
        int op;
        scanf("%d%d%d", &l, &r, &op);
        if (op == 1)
            sort(a + l, a + r + 1);
        else
            sort(a + l, a + r + 1, greater<char>());
    }
    printf("%s", a + 1);
    return 0;
}