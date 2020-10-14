110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104


思路1：判定一个二叉树是否是平衡的，首先想到的方法就是对于树中的每个节点都判定它的左右子树是否为平衡二叉树，当前节点是否为平衡二叉树。

代码如下：
```
class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        
        if(isBalanced(root.left) == true && isBalanced(root.right)==true
          && Math.abs(getHeight(root.left)-getHeight(root.right))<=1){
            return true;
        }else{
            return false;
        }
        
    }
    
    public int getHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        
        return 1 + Math.max(getHeight(root.left),getHeight(root.right));
    }
}
```
这种思路是存在一个重复的冗余计算，就是对于树中的每个节点都从头到尾计算了它的深度，这样的话时间复杂度就是$O(n^2)$。这种思路其实是从树的头部往下走。

思路2：其实我们还可以从树的底部往上走，这里的说的从底部往上走，其实最先输入时还是先输入头结点，只是最后返回时会先返回底部的结果，然后如果底部不满足平衡二叉树的要求，那么就直接返回false，一层层的再往上传。所以这种方法其实可以看做是从底向上的。

代码：
```
class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        
       // System.out.println(dfsHeight(root));
        return dfsHeight(root) != -1;
    }
    
    public int dfsHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        
        int leftHeight = dfsHeight(root.left);
        if(leftHeight == -1){
            return -1;
        }        
        
        int rightHeight = dfsHeight(root.right);
        if(rightHeight == -1){
            return -1;
        }
        
        if(Math.abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
```