144. Binary Tree Preorder Traversal


Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?



思路：这题主要是来对二叉树进行前序遍历，即：中左右的顺序。

首先想到的思路就是递归的方法。

代码如下：
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null){
            return res;
        }
        preOrder(root, res);
        return res;
    }
    public void preOrder(TreeNode root, List<Integer> res){
        if(root == null){
            return;
        }
        
        res.add(root.val);
        preOrder(root.left, res);
        preOrder(root.right, res);
        return;
    }
    
}
```




思路二：还可以使用栈来做，我们肯定首先把头结点入栈，需要先打印中间节点的值，所以在循环的第一步就打印当前节点的值。

然后我们需要将节点的左孩子和右孩子入栈。由于栈是先进后出的结构，而我们接下来要打印左孩子的值，所以在入栈的时候需要先将右孩子的值压栈，然后再将左孩子的值压栈，这样的话在遍历到栈的时候，出栈的元素就是左孩子了。

代码如下：
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = new TreeNode();
        stack.push(root);
        
        while(stack.size() >0){
            node = stack.pop();
            res.add(node.val);
            if(node.right != null){
                stack.push(node.right);
            }
            
            if(node.left != null){
                stack.push(node.left);
            }
        }
        return res;
    }
}
```