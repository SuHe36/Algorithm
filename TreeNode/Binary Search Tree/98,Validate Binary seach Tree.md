98. Validate Binary Search Tree


Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


思路：判断一个树是否为二叉搜索树，也就是需要判断每个节点的所有左孩子均小于它，所有的右孩子均大于它。

所以可以使用中序搜索的结果，看看是否为递增的顺序。


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
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }
        
        Stack<Integer> stack = new Stack<>();
        inOrder(root,stack);
        
        int max = stack.pop();
        
        while(stack.size() != 0 ){
            int temp = stack.pop();
            if(temp >= max){
                return false;
            }
            max = temp;
        }
        return true;
    }
    
    public void inOrder(TreeNode root,Stack<Integer> stack){
        if(root == null){
            return;
        }
        inOrder(root.left,stack);
        stack.add(root.val);
        inOrder(root.right, stack);
        
    }
    
}
```