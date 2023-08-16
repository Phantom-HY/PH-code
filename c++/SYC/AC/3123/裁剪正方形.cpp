#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, h, w,ans_1,ans_2;
void fun(ll a,ll b)
{
    if (!b)
        return ;
    ans_1+=a/b,ans_2++;
    fun(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%lld", &t);
    while (t--)
    {
        ans_1=0,ans_2=0;
        scanf("%lld%lld", &h, &w);
        if (h<w)
            swap(h,w);
        fun(h,w);
        printf("%lld %lld %lld\n",ans_1-1,ans_2,ans_1);
    }
    return 0;
}