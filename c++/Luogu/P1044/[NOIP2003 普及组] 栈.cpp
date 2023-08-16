#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll f[25][25];
ll dfs(int i,int j)
{
	if(f[i][j]) return f[i][j]; 
	if(i==0)return 1;
	if(j>0) f[i][j]+=dfs(i,j-1);
	f[i][j]+=dfs(i-1,j+1);
	return f[i][j];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    printf("%lld",dfs(n,0));
    return 0;
}