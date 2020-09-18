Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-10^5 <= Node.val <= 10^5




思路：将一个排序链表，转化为一个平衡的二叉搜索树【左右子树的高度差不超过1】。

首先我们可以将这个排序链表转换为一个数组，然后每次去中间位置的元素作为根节点，把左半区作为左子树，把右半区作为右子树。

代码：
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {

        
        Stack<Integer> stack = new Stack<>();
        while(head != null){
            stack.push(head.val);
            head = head.next;
        }
        int n = stack.size();
        int[] nums = new int[n];
        for(int i = n-1; i>=0; i--){
            nums[i] = stack.pop();
        }

        TreeNode root = createTree(0,n-1,nums);
        
        return root;
        
    }
    
    public TreeNode createTree(int start, int end, int[] nums){
        if(start > end){
            return null;
        }
        int mid = (start + end) /2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = createTree(start, mid-1, nums);
        root.right = createTree(mid+1, end, nums);
        
        return root;
    }
    
    
}
```




思路二：直接用快慢指针来做，每次找到链表的中间节点，要注意的是快慢指针的判别条件是fast != null && fast.next != null。

但是这里在找到中间节点后，需要将中间节点和前半区断开连接，所以我们需要保存一个slow指针的前序指针，然后最后找到中间节点后，需要把它的前置节点的next指向null。



```
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
       if(head == null){
           return null;
       }
        if(head.next == null){
            return new TreeNode(head.val);
        }
        
        ListNode slow = head;
        ListNode fast = head;
        ListNode pre = null;
        while(fast != null && fast.next != null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        pre.next = null;
        TreeNode root = new TreeNode(slow.val); 
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(slow.next);
        return root;
        
    }
        
}
```
