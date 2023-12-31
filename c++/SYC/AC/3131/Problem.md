### 题目描述
衡量一个算法的快慢,一定要考虑数据规模的大小

一般来说,数据规模越大算法的用时就越长

衡量一个算法的效率时,主要看其用时随数据规模而增长的趋势,即 **时间复杂度**

> 在分析时间复杂度时,往往省略常数因子和公式中的低项

给出一个整数$m$其含义为评测用计算机$\text{1s}$的操作数

现在给出$7$种时间复杂度

$O(n!),O(2^n),O(n^4),O(n^3),O(n^2),O(n),O(n \log_2 n)$

若$m=10^8$,设计的算法时间复杂度为$O(n^3)$,输入的规模$n=50$,那么$n^3 = 6250000\leq m=10^8$,可以称该算法为可接受

若$m=10^8$,设计的算法时间复杂度为$O(n^2)$,输入的规模$n=10001$,那么$n^2 = 100020001 \gt m=10^8$,可以称该算法为超时

### 输入格式
第一行输入一个整数$T$,表示$T$组别询问

每组询问输入三个整数$m,n,t$

+ $t=1$时,算法时间复杂度为$O(n!)$.

+ $t=2$时,算法时间复杂度为$O(2^n)$.

+ $t=3$时,算法时间复杂度为$O(n^4)$.

+ $t=4$时,算法时间复杂度为$O(n^3)$.

+ $t=5$时,算法时间复杂度为$O(n^2)$.

+ $t=6$时,算法时间复杂度为$O(n)$.

+ $t=7$时,算法时间复杂度为$O(n \log_2 n)$.

### 输出格式
对于每组询问输出一行,若算法可接受输出`AC`否则输出`TLE`

### 输入样例
```
6
100000000 500 3
100000000 50 3
100000000 10001 5
100000000 10000 5
19931568 1000000 6
19931569 1000000 6
```
### 输出样例
```
TLE
AC
TLE
AC
AC
AC
```
### 数据规模
对于$30\%$的数据,$n \leq 100,1 \leq T \leq 100 $
对于$100\%$的数据,$1 \leq m,n \leq 10^9,t \in [1,7],1 \leq T \leq 10^5 $