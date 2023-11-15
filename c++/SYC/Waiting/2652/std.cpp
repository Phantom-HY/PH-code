#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    SegTree<int> g(a, n);
    return 0;
}