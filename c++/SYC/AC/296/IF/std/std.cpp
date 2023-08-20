#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char st[100005];
int ans[100005];
int s[100005],len;
int main()
{
    scanf("%s", st);
    int len = 0;
    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] == ')')
            ans[s[len--]] = i + 1;
        else
            s[++len]=i;
    }
    for (int i = 0, cnt = 0; i < strlen(st) && cnt != strlen(st) / 2; i++)
        if (ans[i] != 0)
            printf("%d\n", ans[i]), cnt++;
    return 0;
}