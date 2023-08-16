#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string a;
int num[5005], len, cnt,ans;
void dfs(int x,int step,int k)
{
    if (step%3==0)
    {
        ans=min(ans,k);
        return;
    }
    if (k>=ans)return;
    if (x==len+1)return ;
    dfs(x+1,step-num[x],k+1);
    dfs(x+1,step,k);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> a;
        cnt = len = 0;
        ans=1e9;
        for (auto &&i : a)
            if ((i - '0') % 3 != 0)
                cnt += (i - '0'), num[++len] = (i - '0');
        dfs(1,cnt,0);
        if (ans!=a.size())printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}