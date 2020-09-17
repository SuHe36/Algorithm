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


思路3：还可以使用莫里斯遍历，使用O(n)的时间复杂度，也就是将根节点的左子树的最右节点指向根节点。

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
        
        TreeNode pre = new TreeNode(); //表示根节点的左子树额最右节点，也就是根节点的前置节点
        while(root != null){
            //先实现将左子树的最右节点指向根节点
            if(root.left != null){
                pre = root.left;
                while(pre.right != null){
                    pre = pre.right;
                }
                pre.right = root;
                //将左子树的最右节点指向根节点后，就可以开始将根节点的左节点当做新的根节点，
                //并把当前根节点的左节点置为null
                TreeNode node = root;
                root = root.left;
                node.left = null;
            }else{
                res.add(root.val);
                root = root.right;
            }
        }
        return res;
    }
    
}
```