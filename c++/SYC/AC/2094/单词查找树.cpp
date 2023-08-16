#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char,int>s[100005];
char a[75];
int ans=1;
void dfs(int x,int len)
{
    // printf("%d %d %d %s\n",x,len,strlen(a),a);
    if (len==strlen(a))
        return ;
    if (s[x][a[len]]==0)
    {
        s[x][a[len]]=++ans;
        dfs(ans,len+1);
    }
    else
        dfs(s[x][a[len]],len+1);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while(scanf("%s\n",a)!=-1)
    {
        // printf("%s\n",a);
        dfs(1,0);
    }
    printf("%d",ans);
    return 0;
}