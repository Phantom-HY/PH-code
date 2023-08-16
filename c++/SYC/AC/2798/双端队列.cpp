#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d, x;
deque<int> a;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &d);
        if (d == 0)
        {
            scanf("%d%d", &d, &x);
            if (d == 0)
                a.push_front(x);
            else
                a.push_back(x);
        }
        else if (d == 1)
        {
            scanf("%d", &x);
            printf("%d\n", a[x]);
        }
        else
        {
            scanf("%d",&d);
            if (d == 0)
                a.pop_front();
            else
                a.pop_back();
        }
    }
    return 0;
}