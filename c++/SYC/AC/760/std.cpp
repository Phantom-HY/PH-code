#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
pair<int, int> a;
deque<pair<int, int>> q;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a.first);
        a.second = i;
        if (!q.empty())
        {
            while (q.size() && i - q.front().second > k)
                q.pop_front();
            while (q.size() && a.first > q.back().first)
                q.pop_back();
        }
        q.push_front(a);
        if (i >= k)
            printf("%d ", q.back().first);
    }
    return 0;
}