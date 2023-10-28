#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int sum;
    string s;
    bool operator<(const node &a) const
    {
        return sum > a.sum;
    }
};
int n, k;
unordered_map<string, int> d;
priority_queue<node> a;
int ans = 1e9;
unordered_map<string, bool> vis;
void bl(int step, int dep)
{
    if (step >= ans)
        return;
    if (dep == k + 1)
    {
        ans = step;
        return;
    }
    for (auto &&i : d)
    {
        if (i.first[i.first.size() - 1] != '2')
        {
            if (!vis[i.first])
            {
                vis[i.first] = true;
                bl(step + i.second, dep + 1);
                vis[i.first] = false;
            }
        }
        else
        {
            string s = i.first;
            s[s.size() - 1] = '1';
            if (vis[s]&&!vis[i.first])
            {
                vis[i.first] = true;
                bl(step + i.second, dep + 1);
                vis[i.first] = false;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    cin >> n >> k;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        d[s] = i;
        scanf("%d", &d[s]);
    }
    if (n <= 10 && k <= 10)
        bl(0, 1), printf("%d", ans), exit(0);
    
    return 0;
}