/*# [NOIP2002 普及组] 级数求和

## 题目描述

已知：$S_n= 1+\dfrac{1}{2}+\dfrac{1}{3}+…+\dfrac{1}{n}$。显然对于任意一个整数 $k$，当 $n$ 足够大的时候，$S_n>k$。

现给出一个整数 $k$，要求计算出一个最小的 $n$，使得 $S_n>k$。

## 输入格式

一个正整数 $k$。

## 输出格式

一个正整数 $n$。

## 样例 #1

### 样例输入 #1

```
1
```

### 样例输出 #1

```
2
```

## 提示

**【数据范围】**

对于 $100\%$ 的数据，$1\le k \le 15$。

**【题目来源】**

NOIP 2002 普及组第一题*/





















#include <stdio.h>

int main() 
{
    int  n=1 , k=0;
    double S=1.0 ;

    scanf("%d", &k);
    
    while (S<=k)
    {
        n++;
        S+=1.0/n;
    }

    printf("%d", n);
    
    return 0;
}