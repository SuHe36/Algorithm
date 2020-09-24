103. Binary Tree Zigzag Level Order Traversal



Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

思路： 使用BFS，层次遍历，然后对于每一层，奇数层就直接在链表后面添加元素，如果是偶数层就在链表头部添加元素。


代码：
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int depth = 0;
        
        while(! queue.isEmpty()){
            int n = queue.size();
            List<Integer> list = new ArrayList<>();
            for(int i=0; i<n;i++){
                TreeNode node = queue.poll();
                if(depth %2 == 0){
                    list.add(node.val);
                }else{
                    list.add(0,node.val);
                }
                
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
            }
            depth += 1;
            res.add(list);
            
        }
        return res;
    }
    
}
```



思路二：使用dfs，每次递归到新的深度，就新建一个新的list，然后每次递归到偶数层就在链表头部添加节点，递归到奇数层，就在链表尾部添加节点。


代码：
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        
        dfs(res, root, 0);
        return res;
    }
    
    public void dfs(List<List<Integer>> res, TreeNode root, int depth){
        if(res.size() - 1 < depth){
            res.add(new ArrayList<>());
        }
        
        if(depth % 2 == 0){
            res.get(depth).add(root.val);
        }else{
            res.get(depth).add(0,root.val);
        }
        
        if(root.left != null){
            dfs(res, root.left, depth+1);
        }
        
        if(root.right != null){
            dfs(res, root.right, depth+1);
        }
        
    }
    
}
```