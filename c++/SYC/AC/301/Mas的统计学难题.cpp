#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y;
unordered_map<int,int>m,w;
int main(){
// #ifndef ONLINE_JUDGE
//     freopen("data.in", "r", stdin);
//     freopen("data.out", "w", stdout);
// #endif
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d%d",&x,&y);
        if (x==1)
            w[m[y]]--,m[y]++,w[m[y]]++;
        else 
            printf("%d\n",w[y]);
    }
    return 0;
}