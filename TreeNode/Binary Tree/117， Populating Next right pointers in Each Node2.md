117. 填充每个节点的下一个右侧节点指针 II

给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 

示例：



输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

树中的节点数小于 6000
-100 <= node.val <= 100

思路：二叉树不再是满二叉树，使用常量空间来完成next指针的指向。

由于不是满二叉树，所以我们无法用递归的方法来做，因为当前节点的左右子孩子的next指针指向谁无法确定。

这题可以用迭代来做，我们最先想到的就是用队列来做，队列里按照每一层的先后顺序构建next指针。但这是O(n)的空间复杂度。

其实我们还可以利用在构建第i层的next指针时，就可以把第i+1层的next指针也构建了，因为在遍历第i层时，我们同时可以知道它们有没有左右孩子，我们可以再遍历第i层时，对第i+1层先虚构一个头结点dummy，他指向第i+1层的第一个节点，然后迭代构建next指下去。


代码：
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
        

        curr = root
        
        while curr:
            dummy = Node(0)
            prev = dummy
            while curr:
                if curr.left:
                    prev.next = curr.left
                    prev = prev.next
                if curr.right:
                    prev.next = curr.right
                    prev = prev.next
                    
                curr = curr.next
            curr = dummy.next
        return root
                
        
```