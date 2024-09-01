#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int l,r;
bool check(int a)
{
    int b = a;
    while(b)
    {
        if(a%(b%10) !=0)
            return 0;
        b/=10;
    }
    return 1;
}
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d",&l,&r);
        ans = 0;
        for (int i = l;i<=r;i++)
            if (check(i))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}