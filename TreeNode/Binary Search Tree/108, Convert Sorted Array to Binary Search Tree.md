108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


 思路：要将一个排好序的数组转换成一个高度均衡的二叉搜索树。

 我们需要知道二叉搜索树都是根节点大于左孩子，小于右孩子，所以每次选取有序数组的中间值作为根节点，那么前面的都作为左子树，右边的都作为右子树，已经能够满足是二叉搜索树的要求。

 高度均衡则是因为，我们每次都是选取中间节点作为根节点，那么其左右孩子的高度差肯定会小于1.

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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0){
            return null;
        }
        int left = 0;
        int right = nums.length-1;
        TreeNode root = createNode(nums,left,right);
        return root;
        
        
    }
    
    public TreeNode createNode(int[] nums, int left, int right){
        if(left > right){
            return null;
        }
        int mid = left +(right-left)/2;
        TreeNode root = new TreeNode();
        root.val = nums[mid];
        root.left = createNode(nums, left, mid-1);
        root.right = createNode(nums,mid+1, right);
        return root;
                    
    }
}
 ```