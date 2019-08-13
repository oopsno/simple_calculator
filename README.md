# Simple Calculator

An answer to the problem given by xp.

> 大家好，欢迎大家来 SSSTA 一起玩耍。
>
> 给大家开放式的高三暑假一点编程挑战题，希望能够带来一些美好的回忆。
>
> 那么，如果题目有人做出来了，可在群里 @13-xp 让他给你卖个萌。
>
> ## 第一道题
>
> 题目描述：解析“逆波兰表达式”法表示的一串整数四则运算。
>
> 样例输入：1 2 3 + *
>
> 样例解释：相当于 1*(2+3)
>
> 样例输出：5
>
> 改进：支持负数(negative)，例题 "-1 1 +"，应输出 0  
> 改进：支持浮点数(float)，例题 "0.3 0.5 +"，相当于 0.3+0.5，应输出 0.8，可能有误差，不管  
> 改进：支持数学常量 pi 和 e，例题 "pi"，应输出 3.1415926，我忘了精度能到多少了，不管不管能输出就行  
> 改进：支持三角函数 sin cos tan，例题 "pi 4 / sin"，相当于 sin(pi/4)，应输出 0.5  
>
> ## 第二道题
> 
> 题目描述：解析四则运算的中缀表达式，实现第一道题里的所有功能。注意，中缀表达式包含明确的括号。
>
> 样例输入：-1+13+6*(4+1)
>
> 样例输出：42
