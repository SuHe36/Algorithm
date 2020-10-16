113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


思路：找到从根节点到叶子节点和为sum的所有路径。

具体解决方法就是用回溯来做，这里要注意每次遍历时，中间路径要对当前节点进行add和remove。并且最后要用res.add(new ArrayList<>(ans))来添加新路径，不能用res.add(ans)，因为ans会回传和不断改变。

具体代码：
```
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        getPath(root, sum, ans ,res);
        return res;
    }
    
    public void getPath(TreeNode root, int sum, List<Integer> ans, List<List<Integer>> res){
        if(root == null){
            return;
        }
        
        ans.add(root.val);
        if(root.left == null && root.right == null && root.val == sum){
            res.add(new ArrayList<>(ans));
            ans.remove(ans.size()-1);
            return;
        }

        getPath(root.left, sum-root.val, ans, res);
        getPath(root.right, sum-root.val, ans, res);
        ans.remove(ans.size()-1);
        return;
    }
    
}
```