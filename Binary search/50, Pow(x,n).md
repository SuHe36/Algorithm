实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

思路：用二分法来做

这题的难点在于，要从n到1的过程来做。我们平时做的比较多的都是从1到n来做的。

那么这种题的解法，就是假设已经知道了n/2的结果，用它来计算n的结果。

并且在最终的dfs循环中，用n==1或者n=0来做最底层的结果。

代码：
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0 :
            return 1.0 / self.dfs(x, -n)
        else:
            return self.dfs(x, n)
    def dfs(self, x, n):
        if n == 0:
            return 1
        num = self.dfs(x,n//2)
        if n%2 == 1:
            return num*num*x
        else:
            return num*num
```


真正的二分法，这种写法需要自己代入具体的case来解析。

代码如下：
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1/x
            n = -n

        res = 1
        while n:
            if n%2 == 1:
                res = res*x
            x = x*x
            n = n//2
        
        return res
```



使用递归的方法来做，主要是只算一次mypow(x,n//2)，代码如下：
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 1:
            return x
        elif n == 0:
            return 1
        
        flag = 0
        if n < 0:
            flag = 1
            n = -n
        
        ans = self.myPow(x, n//2)

        if n %2 ==0:
            res =  ans*ans
        else:
            res = x*ans*ans
        
        if flag == 1:
            return 1/res
        else:
            return res
```