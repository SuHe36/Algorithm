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




思路二： 还可以使用栈的方法来构造二叉树。

具体方法就是先使用栈存储先序序列的第一个节点，然后将一个指针指向中序序列的第一个节点。

然后开始遍历先序的结果，如果先序的当前节点不等于中序的指针指向的节点，那么先序的当前节点就是栈中前一个元素的左孩子。

如果先序的当前节点等于中序的指针指向的节点，那么就意味着我们达到了当前分支的最左孩子，然后就把栈中的元素出栈，然后再把中序序列的指针往前移动，直到栈顶的元素和中序的指针指向的节点不同。此时就把先序序列的当前元素就是栈最后一个出栈的右孩子。


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
    public TreeNode buildTree(int[] preorder, int[] inorder) {

        int n = preorder.length;
        if(n == 0){
            return null;
        }
        
        TreeNode root = new TreeNode(preorder[0]);
        int inorderIndex = 0;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        
        for (int i =1; i < n; i++){
            
            TreeNode node = new TreeNode(preorder[i]);
            if(stack.peek().val != inorder[inorderIndex]){
                TreeNode p = stack.peek();
                p.left = node;
                stack.push(node);
            }else{
                TreeNode temp = new TreeNode();
                while(!stack.isEmpty() && stack.peek().val == inorder[inorderIndex]){
                    temp = stack.pop();
                    inorderIndex += 1;
                }
                temp.right = node;
                stack.push(node);
            }
        }
        
        return root;
        
    }
    
}
```