104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

# 思路：求解一棵树的最大深度，可以使用递归的方法，还可以使用dfs（先序遍历，注意这部分的代码会用到Pair<>这个接口），bfs(层次遍历)

代码1：递归
```
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int max = 0;
        max = Math.max(max, 1+maxDepth(root.left));
        max = Math.max(max, 1+maxDepth(root.right));
        return max; 
        
    }

}
```

代码2：dfs
```
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        Pair<TreeNode, Integer> pair = new Pair<>(root,1);
        Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
        
        stack.push(pair);
        int depth=0;
        while(! stack.isEmpty()){
            Pair<TreeNode, Integer> p = stack.pop();
            TreeNode node = p.getKey();
            Integer h = p.getValue();
            depth = Math.max(depth, h);
            
            if(node.right != null){
                stack.push(new Pair<>(node.right, h+1));
            }
            if(node.left != null){
                stack.push(new Pair<>(node.left, h+1));
            }
        }
        return depth;
    }
}
```

代码3：bfs
```
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        int depth = 0;
        queue.offer(root);
        
        while(! queue.isEmpty()){
            int n = queue.size();
            depth += 1;
            for(int i=0; i<n;i++){
                TreeNode node = queue.poll();
                if(node.left != null){
                    queue.offer(node.left);
                }
                
                if(node.right != null){
                    queue.offer(node.right);
                }
            }
        }
        return depth;
    
    }
}
```