114. Flatten Binary Tree to Linked List


Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6



思路：将一个二叉树转换为有序列表，显然是先序遍历的结果，因为这里需要将右子树接在左子树的后面，所以我们显然需要找到左子树的最右节点，因为右子树就是接在它的后面的。

然后我们实现的时候可以采用递归的方法，也可以采取迭代的方法。

注意递归的方法，我们可以先不管每个子任务里面做了什么，先默认每个子任务完成了对二叉树的转换为有序列表的形式，然后来处理当前节点。**注意，这里要在默认左右子树已经处理好的基础上来做。**

递归代码:
```
class Solution {
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        
        flatten(root.left);
        flatten(root.right);
        TreeNode left = root.left;
        TreeNode right = root.right;
        
        if(left != null){
            TreeNode node = left;
            while(left.right != null){
                left = left.right;
            }
            
            left.right = right;
            root.right = node;
            root.left = null;
                
        }else{
            root.left = null;
        }
        return;
        
    }  
}
```


迭代代码：
```
class Solution {
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        
        while(root != null){
            TreeNode left = root.left;
            TreeNode right = root.right;

            if(left != null){
                TreeNode node = left;
                TreeNode prev = null;
                while(left.right != null){
                    left = left.right;
                }
                left.right = root.right;
                root.right = node;
                root.left = null;
            }
            root = root.right;
        }

    }
}
```