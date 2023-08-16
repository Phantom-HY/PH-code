#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[15],ans=1e9,cnt;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),cnt+=abs((a[i]/10)-(a[i]%10));
    sort(a+1,a+1+n);
    do
    {
        int num=cnt;
        for (int i=2;i<=n;i++)
            num+=abs((a[i-1]%10)-(a[i]/10));
        ans=min(ans,num);
    } while (next_permutation(a+1,a+1+n));
    printf("%d",ans);
    return 0;
}