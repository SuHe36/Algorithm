101. Symmetric Tree


Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

思路：判断一棵树是否为镜像的，那么我们需要对一个节点的左右节点进行判断，可以使用递归的方法来做，
一层一层的往下走.


代码：
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        return isSyn(root.left, root.right);
    }
    
    public boolean isSyn(TreeNode left, TreeNode right){
        if(left == null && right == null){
            return true;
        }
        if(left == null || right == null){
            return false;
        }
        if(left.val != right.val){
            return false;
        }
        
        return isSyn(left.left, right.right) && isSyn(left.right, right.left);
        
    }
}
```


