105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

思路：用先序遍历和中序遍历实现构造二叉树，那么就可以根据先序遍历找到根节点的值，
然后再根据根节点的值，去中序遍历里面找到左半部分和右半部分。

代码：
```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        return build(preorder, inorder, 0, 0, n-1);
    }
    
    public TreeNode build(int[] preorder, int[] inorder, int index, int start, int end){
        if(start > end){
            return null;
        }
        
        if(start == end){
            return new TreeNode(inorder[start]);
        }
        
        TreeNode root = new TreeNode(preorder[index]);
        
        int inorderIndex = -1;
        for(int i = start; i<=end; i++){
            if(inorder[i] == preorder[index]){
                inorderIndex = i;
            }
        }
        
        int ls = start;
        int le = inorderIndex -1;
        int rs = inorderIndex+1;
        int re = end;
        int ind_l = index + 1;
        int ind_r = index + inorderIndex -start +1;
        root.left = build(preorder, inorder, ind_l, ls,le);
        root.right = build(preorder, inorder, ind_r, rs, re);
        return root;
        
    }
    
}
```