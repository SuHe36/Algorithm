
这里需要注意python的dict的三种拷贝方式。
```
d1 = {"a":1,"b":[1,2,3]}
d2 = d1
# 这种方式是直接复制，其实d2和d1指向的是内存中的同一块地址

d3 = d2.copy()
# 这种方式是浅拷贝，如果value的值是1这种Int或者str类型，那么修改d1，d3不会跟着修改。但是如果value是[1,2,3]这种list，那么修改d1后，d3的值也会跟着改变，因为这两个的value都是list，在拷贝时也是直接复制过来的，指向的是内存中的同一块地址。

import copy
d4 = copy.deepcopy(d1)
# 这种方法叫做深拷贝，无论d1怎么变，都不会改变d4
```


参考地址：

https://blog.csdn.net/u010895119/article/details/79418434

https://stackoverflow.com/questions/5105517、deep-copy-of-a-dict-in-python