94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

思路：对一个二叉树进行中序遍历，首先想到的就是递归的方法。

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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        inOrder(root, res);
        return res;
        
    }
    
    public void inOrder(TreeNode root, List<Integer> res){
        if(root == null){
            return;
        }
        
        inOrder(root.left, res);
        res.add(root.val);
        inOrder(root.right, res);
        return;
    }
    
}
```


思路二：使用迭代的方法，也就是使用一个栈

代码：
```
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = new TreeNode();
        
        while(stack.size() >0 || root != null){
            while(root != null){
                stack.push(root);
                root = root.left;
            }
            node = stack.pop();
            res.add(node.val);
            root = node.right;
        }
      
        return res;
        
    }
    
}
```