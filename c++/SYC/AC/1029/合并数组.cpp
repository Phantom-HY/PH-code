#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int len_1,len_2,a[1000005],b[1000005];
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&len_1,&len_2);
    for (int i=1;i<=len_1;i++)
        scanf("%d",a+i);
    for (int i=1;i<=len_2;i++)
        scanf("%d",b+i);
    int l_1=1,l_2=1;
    while (l_1<=len_1||l_2<=len_2)
    {
        if (l_2>len_2||(l_1<=len_1&&a[l_1]<=b[l_2]))
            printf("%d\n",a[l_1++]);
        else 
            printf("%d\n",b[l_2++]);
    }
    return 0;
}