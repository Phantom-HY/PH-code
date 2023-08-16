#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
int cnt[100000005];
int len;
int ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&k);
    while (k--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        len=max(len,r);
        cnt[l]++;
        cnt[r+1]--;
    }
    for (int i=1;i<=len;i++)
        cnt[i]+=cnt[i-1],ans=max(ans,cnt[i]);
    printf("%d",ans);
    return 0;
}