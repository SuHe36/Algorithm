给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。



思路：这题相当于在txt【haystack串】中找到target【needle】串第一次出现的位置。
暴力解法，对于txt串中的每一个位置都进行匹配。


代码如下：
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

 
        for i in range(len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)] == needle:
                return i

        return -1
```




思路2：KMP算法

这里的难点在于KMP中对于target串，自己建立自己的next数组。


KMP算法的核心就是在txt串和target串进行匹配时，txt串的指针只会往前移，不会回头。

这里就需要对于target串建立next数组。而建立next数组，其实就是在target串中找到前缀和后缀的最大匹配长度。

具体建立next数组的思路可以参考：
https://binary-baba.medium.com/string-matching-kmp-algorithm-27c182efa387

https://towardsdatascience.com/pattern-search-with-the-knuth-morris-pratt-kmp-algorithm-8562407dba5b


我写的一个专门来获取target串的next数组的代码【测试case可以使用经典case"ACABACACD"】：


```
def getNext(w):
    # 构建next数组的核心思想就是，求当前位置的后缀和起始点的前缀的最大的公共子序列的长度
#     http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
    array = [0]*len(w)
    
    i = 1
    m = 0
    
    while i < len(w):
        print("i is:{}\t m is:{}\t array is:{}".format(i,m,array))

        if w[i] == w[m]:
            # 当前位置i的值和前缀位置相等，那么可以给m+1，因为m初始值为0，然后赋值给array[i]
            # 同理当后续i+1和m+1的位置相等时，可以不断的迭代下去
            m += 1
            array[i] = m
            i += 1
        elif w[i] != w[m] and m != 0:
            # 这里是当i和m位置的值，不相等，并且m不等于；
            # 这种情况就是比如字符串"ACABACACD"走到i=7时，此时m=3，因为第4个字符到第6个字符"ACA"和第0个字符到底2个字符"ACA"相等，
            # 但是此时第7个字符"C"和第3个字符"B"不相等，那么我们此时要如何操作呢？
            # 此时，我们要铭记我们的next数组的主旨是要存储当前位置i的后缀和起始位置0的最长匹配串。
            #【我们此时之所以匹配第i个字符和第m个字符是否相等，是因为我们已经知道第0到第m-1个字符和从第i-m-1到第i-1个字符相等】
            # 既然从0到m位置的匹配无法成功，那么我们就需要缩短匹配的字符串长度，此时我们其实是知道第i-1个字符串和第m-1个字符是相等的，
            # 那么我们其实可以找到第m-1个字符串的最长匹配长度，在他的基础上再来匹配最长长度。
            # 也就是我们其实根据next数组array还知道一个信息，就是从第0个字符到第array[m-1]-1个字符
            # 其实和从第i-array[m-1]个字符到第i-1个字符是相等的【这个信息其实是根据array[m-1]的值得到的】；
            # 所以我们接下来需要判断第i个字符和第array[m-1]个字符是否相等
            # 所以这里其实也可以写成循环的方式
            # 注意这里对i没有执行+1操作
            m = array[m-1]
        else:
            array[i] = 0
            i += 1
            
        
        
    return array

```


具体的找到target串，在txt中第一次出现的代码如下：

```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        na = self.getNext(needle)

        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1

                if j == len(needle):
                    return i-j 
            elif haystack[i] != needle[j]:
                if j == 0:
                    i += 1
                else:
                    j = na[j-1]
        return -1
    def getNext(self, target):
        array = [0]*len(target)

        value = 0
        start = 1
        while start < len(target):
            if target[start] == target[value]:
                value += 1
                array[start] = value
                start += 1
            elif target[start] != target[value] and value != 0:
                value = array[value-1]
            else:
                array[start] = 0
                start += 1
        
        return array

```



如果我们想要求所有出现过的target串的位置的话，可以把代码改成：
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        na = self.getNext(needle)

        i = 0
        j = 0
        res = [] 
        # 用res数组来存储所有target串在txt中出现的起始位置
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1

                if j == len(needle):
                    # return i-j 
                    res.append(i-j)
                    j = na[j-1]
                    # 这里同样还是移动j指针，也就是指向target串的指针的位置，和构建next数组时一样。

            elif haystack[i] != needle[j]:
                if j == 0:
                    i += 1
                else:
                    j = na[j-1]
        return -1
    def getNext(self, target):
        array = [0]*len(target)

        value = 0
        start = 1
        while start < len(target):
            if target[start] == target[value]:
                value += 1
                array[start] = value
                start += 1
            elif target[start] != target[value] and value != 0:
                value = array[value-1]
            else:
                array[start] = 0
                start += 1
        
        return array

```