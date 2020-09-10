95. Unique Binary Search Trees II
Medium

2432

161

Add to List

Share
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8



思路：给了一个数字n，求从1~n能组成的二叉搜索树的所有可能的情况。

显然可以使用递归，对于每个数字i，都可以当做根节点，然后1~i-1组成左子树，i+1~n组成右子树。

然后对于当前根节点i，遍历所有的左子树和右子树构建树。


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
    public List<TreeNode> generateTrees(int n) {
        if (n==0){
            return new ArrayList<>();
        }
        
        List<TreeNode> res = generate(1,n);
        return res;
    }    
    
    public List<TreeNode> generate(int start, int end){
        List<TreeNode> list = new ArrayList<>();

        if(start > end){
            list.add(null); 
            return list;
            //注意这里必须在返回前执行list.add(null);
            //不能直接返回null或者new ArrayList<>(),直接返回会报错
            //我觉得原因是后面需要遍历所有可能的左右子树，所以需要有null值
        }
        
        for(int i = start; i<=end; i++){
            List<TreeNode> left = generate(start, i-1);
            List<TreeNode> right = generate(i+1,end);
            // System.out.println("start:"+start +",i:"+i+",end:"+end);
            // System.out.println("left:"+left);
            for (TreeNode l : left){
                for(TreeNode r : right){
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    list.add(root);
                }
            }
        }
        return list;
    }
}
```



解法二：动态规划

缓存从1~m的所有可能的二叉搜索树，因为对于每一颗二叉搜索树，节点为i，它的左子树节点为1~i-1，右子树节点为i+1~n，其中i+1~n的所有可能情况与1~n-i的构成结构是一样的，区别只是所有节点的值要比1~n-i的大i而已。

所以，我们可以缓存每个1~i的二叉搜索树的情况，那么当构建右子树时，可以把1~i的结构再取出来，只是将它们的节点值都加i就行。

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
    public List<TreeNode> generateTrees(int n) {
        ArrayList<TreeNode>[] dp = new ArrayList[n+1];
        dp[0] = new ArrayList<TreeNode>();
//      这里必须对dp[0]进行初始化，因为前面构建的dp数组，并没有直接对每一个dp[i]设置默认值，
//      如果没有初始化，后面的dp[0].add(null)，会说dp[0]是一个空指针
        if(n==0){
            return dp[0];
        }
        dp[0].add(null);
        
        for(int len=1; len<=n; len++){
            dp[len] = new ArrayList<TreeNode>();
//             同上，这里必须初始化
            for(int val=1; val<=len; val++){
                for(TreeNode left: dp[val-1]){
                    for(TreeNode right : dp[len-val]){
                        TreeNode root = new TreeNode(val);
                        root.left = left;
                        root.right = copy(right, val);
                        dp[len].add(root);
                    }
                }
            }
        }
        return dp[n];
    }
    public TreeNode copy(TreeNode node, int offset){
        if(node == null){
            return null;
        }
        TreeNode r = new TreeNode(node.val+offset);
        r.left = copy(node.left, offset);
        r.right = copy(node.right, offset);
        
        return r;
    }
}
```