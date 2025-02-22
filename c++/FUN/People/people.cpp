#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int year[50005][2];
void solve(int x,int s)
{
    int a, b;
    a = b = 0;
    for (int i = 1; i <= 100 && x >= 0; i++, x--)
        a += year[x][0], b += year[x][1];
    printf("%dYear %d:%d Boy:%lf Girl:%lf\n",s,a,b,(double)a/(double)(a+b),(double)b/(double)(a+b));
}
int main()
{
    freopen("people.out","w",stdout);
    srand(time(NULL));
    int t;
    year[0][0] = rand() + 1,year[0][1] = rand() + 1;
    year[1][0] *= rand() + 1,year[1][1] *= rand() + 1;
    t = rand() % 50000 + 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1;j <= min(year[i-1][0],year[i-1][1]);j++)
            if (rand() % 2)
                year[i][0]++;
            else
                year[i][1]++;
        int p_1,p_2;
        p_1 = rand() % 500 + 1;
        p_2 = rand() % 500 + 1;
        year[i][0] = year[i][0] * p_1 / 100;
        year[i][1] = year[i][1] * p_2 / 100;
        year[i][0]++, year[i][1]++;
        solve(i, i);
    }
    return 0;
}