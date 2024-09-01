#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mmonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool c(int year)
{
    return year % 4 == 0 && year % 100 || year % 400 == 0;
}
void fun(int x)
{
    int year = 1900;
    while (x)
    {
        int d = c(year) ? 366 : 365;
        if (x == d)
        {
            printf("%d-12-31\n", year);
            break;
        }
        else if (x < d)
        {
            printf("%d-", year);
            int m = 1;
            if (c(year))
            {
                while (x > mmonth[m])
                {
                    x -= mmonth[m];
                    m++;
                }
            }
            else
            {
                while (x > month[m])
                {
                    x -= month[m];
                    m++;
                }
            }
            printf("%02d-%02d\n", m, x);
            break;
        }
        else
            x -= d, year++;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &y);
    for (x = 0; x <= 23; x++)
        fun(365.242 * (y - 1900) + 6.2 + 15.22 * x - 1.9 * sin(0.262 * x));
    return 0;
}