### 题目描述
给定一个正整数$X$

请你求出

$
\displaystyle \sum_{k=0}^{\infty} \left \lfloor \frac{X}{10^k} \right \rfloor
$

的结果

> 其中 $ \lfloor \dfrac{12}{10} \rfloor$表示$\dfrac{12}{10}$向下取整的结果

### 输入格式

输入一个正整数$X$

### 输出格式
输出一个整数表示答案

### 输入样例1
```
12345
```
### 输出样例1
```
13715
```
### 样例解释1
$\displaystyle \left \lfloor \dfrac{12345}{10^0} \right \rfloor+\displaystyle \left \lfloor \dfrac{12345}{10^1} \right \rfloor+\displaystyle \left \lfloor \dfrac{12345}{10^2} \right \rfloor+\displaystyle \left \lfloor \dfrac{12345}{10^3} \right \rfloor+\displaystyle \left \lfloor \dfrac{12345}{10^4} \right \rfloor+\displaystyle \left \lfloor \dfrac{12345}{10^5} \right \rfloor+\cdots+\displaystyle \left \lfloor \dfrac{12345}{10^{100}} \right \rfloor$

$=12345+1234+123+12+1+0+\cdots$

$=13715$
### 输入样例2
```
99999
```
### 输出样例2
```
111105
```
### 数据规模
对于$20\%$的数据$1 \leq X \leq 10^9$
对于$40\%$的数据$1 \leq X \leq 10^{18}$
对于$100\%$的数据$1 \leq X \leq 10^{500000}$