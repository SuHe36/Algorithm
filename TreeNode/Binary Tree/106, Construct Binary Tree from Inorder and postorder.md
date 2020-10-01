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




思路二：用中序遍历和后续遍历生成二叉树，那么和105题是一样的，我们也可以使用栈来生成二叉树。

和用先序遍历和中序遍历生成二叉树的不同就是，这里是从后往前遍历的。

具体步骤就是用栈存储后序遍历的最后一个结果【也就是根节点的值】，然后用一个指针指向中序遍历的最后一个节点。

接着对后续遍历的结果进行从后往前遍历，当栈顶元素和中序遍历的指针指向的值不同时，就将元素入栈，并且该节点【迭代到的后序遍历的节点值】是栈顶元素的右孩子。

如果相同的话，就将栈顶元素出栈，并且将中序遍历的指针向前移动一个位置，一直到不同时，最后一个出栈的元素的左孩子就是当前的后续遍历的节点值。

代码如下：
```
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        if(n == 0){
            return null;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode root = new TreeNode(postorder[n-1]);
        int inorderIndex = n-1;
        stack.push(root);
        
        for(int i = n-2; i>=0; i--){
            TreeNode node = new TreeNode(postorder[i]);
            if(stack.peek().val != inorder[inorderIndex]){
                TreeNode r = stack.peek();
                r.right = node;
            }else{
                TreeNode r = new TreeNode();
                while(! stack.isEmpty() && stack.peek().val == inorder[inorderIndex]){
                    r = stack.pop();
                    inorderIndex -= 1;
                }
                r.left = node;
            }
            stack.push(node);
        }
    
        return root;
    }   
}
```
