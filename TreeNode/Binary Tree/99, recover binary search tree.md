99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?



思路：搜索二叉树中有两个节点交换了值，要求找到这两个节点交换回来，恢复成搜索二叉树。
要求O(1)的空间复杂度。

这题主要是采取莫里斯中序遍历来做，要记住一般的采取莫里斯中序遍历的步骤是如下：
```
    public void recoverTree(TreeNode root) {
        if (root == null){
            return;
        }
    
        TreeNode prev = null,;
        while(root != null){
            if(root.left != null){
                prev = root.left;
                while(prev.right != null && prev.right != root){
                    prev = prev.right;
                }
                if(prev.right == null){
                    prev.right = root;
                    root = root.left;
                }else{
                    
                    System.out.println(root.val);
                    prev.right = null;
                    //注意断开连接，恢复树的结构是在第二次遍历到当前节点时，判定出了他的左子树的最右节点的右孩子指向了当前节点，那么就将最右节点的右孩子置为null，且此时才输出当前节点。
                    root = root.right;
                }
                
            }else{
                System.out.println(root.val);

                root = root.right;
            }
        }
        
        
    }
```

那么我们只要将上面的system.out.println(root.val)，修改为
```
if(inorderPrev != null && inorderPrev.val > root.val ){
    if(first == null){
        first = inorderPrev;
        second = root;
    }else{
        second = root;
        }
    }
inorderPrev = root;
```
就可以了。

完整的代码如下：
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
    public void recoverTree(TreeNode root) {
        if (root == null){
            return;
        }
    
        TreeNode prev = null, inorderPrev = null;
        TreeNode first = null, second = null;
        while(root != null){
            if(root.left != null){
                prev = root.left;
                while(prev.right != null && prev.right != root){
                    prev = prev.right;
                }
                if(prev.right == null){
                    prev.right = root;
                    root = root.left;
                }else{
                    if(inorderPrev != null && inorderPrev.val > root.val ){
                        if(first == null){
                            first = inorderPrev;
                            second = root;
                        }else{
                            second = root;
                        }
                    }
                    inorderPrev = root;
                    
                    prev.right = null;
                    root = root.right;
                }
                
            }else{
                if(inorderPrev != null && inorderPrev.val > root.val ){
                    if(first == null){
                        first = inorderPrev;
                        second = root;
                    }else{
                        second = root;
                        }
                    }
                inorderPrev = root;
                root = root.right;
            }
        }
        
        if(first != null && second != null){
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
        return;
    }
}
```