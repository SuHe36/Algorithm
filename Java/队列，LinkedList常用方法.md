在java中，常使用LinkedList来模拟队列，因此这里整理一下LinkedList的常用方法，也是队列的常用方法


## 增加
- add(e)：在链表最后添加一个元素，通用的方法
- addFirst(e)：在链表头部插入一个元素；特有的方法
- addLast(e)：在链表尾部添加一个元素；特有方法



## 删除
- remove()：移除链表的第一个元素，通用的方法
- remove(e)：移除指定的元素；通用的方法
- removeFirst(e)：删除头，获取元素并删除；特有方法
- removeLast(e)：删除尾；特有方法
- pollFirst()：删除头；特有方法
- pollLast()：删除尾，特有方法
  
## 查
- get(int index)：按照下标获取元素；通用方法
- getFirst()：获取第一个元素；特有方法
- getLast()：获取最后一个元素；特有方法
- peekFirst()：获取第一个元素，但是不移除
- peekLast():获取最后一个元素，但是不移除


## 队列接口
队列自己有一些特有的操作：
- offer(e)：在链表尾部插入一个元素
- poll(e)：查询并移除第一个元素
- peek()：获取头部元素，不移除

