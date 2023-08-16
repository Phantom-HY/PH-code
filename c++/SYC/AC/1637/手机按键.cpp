#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> s[255], ans;
char a[15];
void bdfs(int x)
{
    if (x == strlen(a))
    {
        for (auto &&i : ans)
            printf("%c", i);
        puts("");
        return;
    }
    for (auto &&i : s[a[x]])
        ans.push_back(i), bdfs(x + 1), ans.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    for (int i = 2; i <= 7; i++)
        for (int j = 'a' + (i - 2) * 3; j <= 'a' + ((i - 1) * 3 - 1); j++)
            s[i + '0'].push_back(j);
    s['9'].push_back('s');
    for (int i = 8; i <= 9; i++)
        for (int j = 'a' + (i - 2) * 3+1; j <= 'a' + ((i - 1) * 3); j++)
            s[i + '0'].push_back(j);
    s['9'].push_back('z');
    scanf("%s", a);
    bdfs(0);
    return 0;
}