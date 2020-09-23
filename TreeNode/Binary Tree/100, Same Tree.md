100. Same Tree


Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
Accepted
610,266
Submissions
1,138,804



思路：给定两棵树，判定他们是否是相同的，显然可以使用深度优先搜索的思路，一层一层的往下走，使用递归的方法来做。

代码：
```
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null){
            return true;
        }
        
        if(p == null || q == null){
            return false;
        }
        
        if(p.val != q.val){
            return false;
        }
        
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
```


思路二：也可以使用广度优先搜索的思路，也就是层序遍历，看看最后遍历的结果是否一样。