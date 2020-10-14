111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.


Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

思路：找到一棵树中，高度最小的叶子节点，我们可以用dfs和bfs的方法来做。

dfs的代码如下：
```
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        
        if(left == 0 || right == 0){
            return Math.max(left, right)+1;
        }else{
            return Math.min(left, right)+1;
        }
    }
}
```

bfs的代码如下：
```
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int res = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(! queue.isEmpty()){
            int n = queue.size();
            res += 1;
            for(int i =0; i<n; i++){
                TreeNode node = queue.poll();
                if(node.left == null && node.right == null){
                    return res;
                }
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
            }
        }
        return res;
    }
}
```