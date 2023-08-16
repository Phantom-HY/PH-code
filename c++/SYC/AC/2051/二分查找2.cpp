#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,x;
int a[100005];
int s(int x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (a[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return a[r]==x?r-1:-1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    while(q--)
    {
        scanf("%d",&x);
        printf("%d\n",s(x));
    }
    return 0;
}