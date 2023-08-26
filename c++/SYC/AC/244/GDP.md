### 题目描述
$M$国含有$n$个城市，每个城市只会被一个城市管辖，除了首都。

首都的编号为$1$，其余城市的编号为$2 \sim n$。每个城市的管辖范围除了它自己以及它直接管辖的城市，还包括它管辖的城市所管辖的城市。

例如$1$管辖$2$，$2$管辖$3$，$3$管辖$4$，$3$管辖$5$，那么$1$，$2$，$3$，$4$，$5$所管辖的城市分别为：$[1, 2, 3, 4, 5]$, $[2, 3, 4, 5]$, $[3, 4, 5]$, $[4]$, $[5]$。

每个城市会产生一个$GDP$值，行政长官想要知道某个城市所管辖的所有城市的$GDP$和是多少。

### 题目输入
第一行一个$n$ 和 $w_1$，表示有$n$个城市和首都的$GDP$值。

接下来有$n-1$行，每一行包含两个数字$f_i$和$w_i$，表示城市$i$被$f_i$城市管辖和城市$i$的$GDP$值。($i \in [2, n]$）。

第$n + 1$行是一个数字$Q$，表示询问次数。

接下来$Q$行，每行一个数字$q_i$，表示询问$q_i$城市所管辖的所有城市的$GDP$值。

### 题目输出
输出$Q$行，每行一个整数表示$q_i$所管辖的所有城市的$GDP$值。
### 样例输入
```
4 4
1 10
1 5
3 1
4
1
2
3
4
```
### 样例输出
```
20
10
6
1
```
### 范围说明
对于$20\%$的数据有：$1 \leq n, Q \leq 10$；
对于$50\%$的数据有：$1 \leq n, Q \leq 100$；
对于$100\%$的数据有：$1 \leq n, Q \leq 10^5,1 \leq w_i \leq 10^9$