### 题目描述
每个网页都由称为$\text{URL}$(统一资源定位器)的字符串标识,所有的网页都可以看作是$\text{HTML}$(超文本标记语言)编写的

$\text{HTML}$中有多种标签,其中超链接标签可以从当前$\text{URL}$跳转到新的$\text{URL}$,用户可以通过点击超链接实现网页的跳转

超链接标签的格式为`<A HREF="URL"></A>`或`<A HREF="URL"/>`,标签中的`URL`为新的$\text{URL}$地址

现在给出$n$个$\text{HTML}$的网页源代码,你需要提取出所有能够跳转的$\text{URL}$

在最后有$m$组询问,每组询问给出两个$\text{URL}$,$\text{URL}_A$和$\text{URL}_B$若能够从$\text{URL}_A$跳转到$\text{URL}_B$,输出`Yes.`否则输出`No.`

### 输入格式

第一行输入两个正整数$n,m$
接下来给出$n$段$\text{HTML}$描述信息
每段信息第一行为当前网页的$\text{URL}$,接下来若干行表示$\text{HTML}$代码,保证最后一行为`</HTML>`

最后$2 \times m$行,每两行给出一组$\text{URL}$,包含$\text{URL}_A$和$\text{URL}_B$

保证所有的$\text{URL}$长度不超过$50$且由可见`ASCII`字符组成,保证所有的超链接标签都在同一行
### 输出格式
对于$n$段$\text{HTML}$描述信息,按照`Link from A to B`的格式输出一行$\text{HTML}$中的超链接信息,其中`A`为当前$\text{URL}$,`B`为跳转到$\text{URL}$

对于$m$组询问每组输出一行,若能够从$\text{URL}_A$跳转到$\text{URL}_B$,输出`Yes.`否则输出`No.`

### 输入样例
```
3 2
http://oj.shiyancang.cn
<HTML> <TITLE>This is the SYCOJ page</TITLE>
Hello there boys
and girls.  <B>Let's</B> try <A HREF="http://noi.ac/problem/1"> a little problem </A>
</HTML>
http://noi.ac/problem/1
<HTML> Now is the <TITLE>time</TITLE> for all good people to program.
<A HREF="http://www.www.www.com">hello</A>
<A HREF="http://xxx">bye</A>
</HTML>
http://www.www.www.com
<HTML>
<TITLE>Weird and Wonderful World</TITLE>
</HTML>
http://oj.shiyancang.cn
http://www.www.www.com
http://www.www.www.com
http://oj.shiyancang.cn
```
### 输出样例
```
Link from http://oj.shiyancang.cn to http://noi.ac/problem/1
Link from http://noi.ac/problem/1 to http://www.www.www.com
Link from http://noi.ac/problem/1 to http://xxx
Yes.
No.
```
### 数据规模
对于全部的数据$1 \leq n \leq 100,1 \leq m \leq 50$,保证输入字符个数不超过$10000$