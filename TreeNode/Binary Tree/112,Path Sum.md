112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


思路：判断树中是否存在一条从根节点到叶子节点的路径，满足和是sum值。

可以用递归的方法做，每次传入新的sum-root.val的值给root.left和root.right，一直到是叶子节点，判断是否满足，然后再往回传【这个往回传就是父亲节点的输出结果要靠左右孩子的返回结果。】


代码：
```
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null ){
            return false;
        }

        
        if( root.left == null && root.right == null){
            if(root.val == sum){
                return true;
            }else{
                return false;
            }  
        }
        
        boolean left = root.left == null? false: hasPathSum(root.left, sum-root.val);
        boolean right = root.right == null? false : hasPathSum(root.right, sum-root.val);
        return left || right;

    }
}
```