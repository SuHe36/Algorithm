102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


思路：对二叉树实现层序遍历，可以使用队列，注意java里的队列是用LinkedList实现的。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root); 
        
        while(!queue.isEmpty()){
            List<Integer> layer = new ArrayList<>();
            int n = queue.size();
            while(n>0){
                TreeNode node = queue.remove();
                layer.add(node.val);
                if(node.left != null){
                    queue.add(node.left);
                }
                if(node.right != null){
                    queue.add(node.right);
                }
                n--;
            }
            res.add(layer);
        }
    return res;
    }
}
```

思路二： 也可以使用dfs， 每次遍历到新的一层时，就新建一个新的ArrayList，然后前序遍历，每次遍历到了该层的节点，就取出对应层的list， 添加在末尾。


代码：
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        dfs(res,root,0);
        return res;
    }
    
    public void dfs(List<List<Integer>> res, TreeNode root, int level){
        if(res.size() -1 < level){
            res.add(new ArrayList<>());
        }
        res.get(level).add(root.val);
        
        if(root.left != null){
            dfs(res, root.left, level+1);
        }
        
        if(root.right != null){
            dfs(res, root.right, level+1);
        }
        
        
    }
}
```