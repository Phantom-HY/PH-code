#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
int w,n,g[55],ans;
void dffs(int x,int k)
{
    if (k>w)
        return ;
    if (x>n/2)
    {
        v.push_back(k);
        return;
    }
    dffs(x+1,k);
    dffs(x+1,k+g[x]);
}
void ddfs(int x,int k)
{
    if (k>w)
        return ;
    if (x>n)
    {
        
        return;
    }
    ddfs(x+1,k);
    ddfs(x+1,k+g[x]);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&w,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",g+i);
    
    return 0;
}