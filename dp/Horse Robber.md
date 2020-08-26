198.  House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400


代码
```
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }

        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            dp[i] = Math.max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
}
```



213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

思路：将首尾连接起来，形成了一个环，这时我们只需将初始情况分成两种。

一个是初始时包含第一个元素，一个是不包含第一个元素，然后分别迭代到n-1和n，再求最大值。
代码：
```
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==0){
            return 0;
        }
        
        if(n==1){
            return nums[0];
        }
        
        int[] dp0 = new int[n];
        int[] dp1 = new int[n];
        
        dp0[0] = nums[0];
        dp0[1] = Math.max(nums[0],nums[1]);
        for(int i=2; i<n-1; i++){
            dp0[i] = Math.max(dp0[i-1],dp0[i-2]+nums[i]);
        }
        
        dp1[1] = nums[1];
        for(int i=2; i<n; i++){
            dp1[i] = Math.max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        
        return Math.max(dp0[n-2],dp1[n-1]);
    }
}
```


337. House Robber III
    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


思路：将数据换成了二叉树的形式，那么抢劫时可以理解为跳层抢劫，所以具体抢劫时，可以分为抢当前层和不抢当前层。

注意这里的抢当前层时，需要跳到当前层的下一层的下一层，所以里面有三元表达式【需要对当前层的下一层做判断】。

代码:
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
    Map<TreeNode, Integer> res = new HashMap<>();
    public int rob(TreeNode root) {
        int max_profit = 0;
        if (root == null){
            return 0;
        }
        
        if(res.containsKey(root)){
            return res.get(root);
        }
        
        
        
        int containRoot = root.val + (root.left == null ?0 : rob(root.left.left)+rob(root.left.right)) + (root.right==null?0:rob(root.right.left)+rob(root.right.right));
        int noRoot = rob(root.left) + rob(root.right);
        
        max_profit = Math.max(containRoot, noRoot);
        res.put(root, max_profit);
        return max_profit;
    }
}
```