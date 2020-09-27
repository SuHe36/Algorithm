106. Construct Binary Tree from Inorder and Postorder Traversal
Medium

2077

38

Add to List

Share
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7



思路： 这题主要是要利用中序遍历和后序遍历构造二叉树，这题的思路和前面的利用前序和中序的思路是一样的。

都是先利用后序找到根节点，然后再利用中序划分左右子树，使用递归的思想。


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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        return build(inorder, postorder, n-1, 0,n-1);

    }
    
    public static TreeNode build(int[] inOrder, int[] postOrder, int index,
                                 int start, int end){
        if(start == end){
            return new TreeNode(postOrder[index]);
        }

        if(start > end){
            return null;
        }
        int value = postOrder[index];

        int inOrderIndex = -1;
        for (int i= start; i <= end; i++){
            if(inOrder[i] == value){
                inOrderIndex = i;
                break;
            }
        }
        int leftStart = start;
        int leftEnd = inOrderIndex -1;
        int rightStart = inOrderIndex + 1;
        int rightEnd = end;
        int rightIndex = index - 1;
        int leftIndex = index - end + inOrderIndex -1 ;
        TreeNode root = new TreeNode(value);
        root.left = build(inOrder, postOrder, leftIndex, leftStart, leftEnd);
        root.right = build(inOrder, postOrder, rightIndex, rightStart, rightEnd);
        return root;

    }
    
    
}
```