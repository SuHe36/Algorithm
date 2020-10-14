889. Construct Binary Tree from Preorder and Postorder Traversal

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

思路：用二叉树的先序遍历和后序遍历构建二叉树，一般来说，不能只由先序和后序搭建二叉树，但是这个二叉树里的每个元素都是不同的，所以可以有先序和后序构建。

具体的就是由先序的第一个元素就是根节点值，接着下一个元素就是左子树的根节点值，然后根据左子树的值去后序遍历里面找到所有的左子树的节点。

代码：
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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        int n = pre.length;
        if(n == 0){
            return null;
        }
        
        return createTree(0, n-1, 0, n-1, pre, post);
    }
    
    public TreeNode createTree(int startPre, int endPre, int startPost, int endPost, int[] pre, int[] post ){
        
        
        if(endPre - startPre < 0){
            return null;
        }
        
        
        if(endPre - startPre == 0){
            return new TreeNode(pre[startPre]);
        }
        
        TreeNode root = new TreeNode(pre[startPre]);
        int index = startPost;
        while(index <= endPost){
            if(post[index] == pre[startPre+1]){
                break;
            }
            index++;
        }
        int len = index - startPost;
        root.left = createTree(startPre+1, startPre+1+len, startPost, index, pre, post);
        root.right = createTree(startPre+2+len, endPre,index+1, endPost-1,pre,post);
        return root;
    }
}
