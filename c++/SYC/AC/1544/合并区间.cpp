#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
pair<int, int> a[100005];
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n);
    int L = a[1].x, R = a[1].y;
    for (int i = 2; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        if (a[i].x <= R)
        {
            R=max(R,r),L=min(L,l);
        }else{
            printf("%d %d\n",L,R);
            L=l,R=r;
        }
    }
    printf("%d %d\n",L,R);
    return 0;
}