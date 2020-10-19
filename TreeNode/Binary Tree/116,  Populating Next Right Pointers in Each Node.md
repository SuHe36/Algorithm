116. 填充每个节点的下一个右侧节点指针

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

思路：可以使用层序遍历和递归的方法来做。

bfs代码：
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        queue = []
        queue.append(root)
        
        while len(queue) > 0:
            size = len(queue)
            for i in range(size -1):
                queue[i].next = queue[i+1]
            queue[size-1].next = None
            
            for i in range(size):
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return root
```


递归的代码：
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        if root.left and root.right:
            root.left.next = root.right
            
            if root.next:
                root.right.next = root.next.left
            
            self.connect(root.left)
            self.connect(root.right)
        return root
```

