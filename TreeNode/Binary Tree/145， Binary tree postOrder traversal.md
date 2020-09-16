145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100




思路：对二叉树进行后序遍历，可以使用递归和栈


代码一：
```
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        
        dfs(root, res);
        return res;
        
    }
    
    public void dfs(TreeNode root, List<Integer> res){
        if(root == null){
            return ;
        }
        
        dfs(root.left, res);
        dfs(root.right, res);
        res.add(root.val);
    }
}
```



代码二：
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null){
            return ans;
        }
        
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> res = new Stack<>();
        
        stack.push(root);
        TreeNode node = new TreeNode();
        while(stack.size() > 0){
            node = stack.pop();
            res.push(node.val);
            if(node.left != null){
                stack.push(node.left);
            }
            
            if(node.right != null){
                stack.push(node.right);
            }
        }
        
        while(res.size() > 0){
            int element = res.pop();
            ans.add(element);
        }
        return ans;
    }
    
}
```