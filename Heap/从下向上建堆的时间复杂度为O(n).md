首先从上向下建堆的时间复杂度为O(nlogn)，因为每一次插入都可能需要比较logn次。

而从下向上建堆的时间复杂度却是O(n)。

首先从下向上建堆时，循环是从i=heapsize/2 开始一直到1的。

具体的建堆过程可以参考我写的堆排序的过程。

那么就有1/2的元素向下比较了一次，有1/4的元素向下比较了两次，1/8的元素向下比较了3次，...,1/2^k的向下比较了k次。

其中1/2^k <=1，约等于log(n)，于是就有总的计算次数：
$$T = (\sum_{k=1}^{log(n)}\frac{1}{2^k}\times k)*n$$

我们令其中的$S = \sum_{k=1}^{log(n)}\frac{1}{2^k}\times k$,

那么可得：
$$\frac{1}{2}S = \sum_{k=1}^{log(n)}\frac{1}{2^{k+1}}\times k = \frac{1}{4} + \frac{1}{8}\times 2 +...+ \frac{1}{2^{k+1}}\times k $$

计算$S-\frac{1}{2}S = \frac{1}{2} = \frac{1}{2} + \frac{1}{4} + ... + \frac{1}{2^k} - \frac{1}{2^{k+1}}\times k$

有等比数列求和$sum = a_1\frac{1-q^n}{1-q}$可得：
$$\frac{1}{2}S =\frac{1}{2}\times\frac{1-(\frac{1}{2})^k}{1-\frac{1}{2}} - \frac{1}{2^{k+1}}\times k= 1-\frac{1}{2^k}-\frac{1}{2^{k+1}}\times k$$

所以我们可以得出：
$$S \leq 2$$

也就是$T \leq 2 $即$T=O(n)$