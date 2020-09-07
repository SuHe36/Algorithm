25. Reverse Nodes in k-Group


Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.


思路：对一个链表每k个元素进行一个反转，如果剩余元素不足k个，那么就不对其进行操作。

这题的主要思路就是需要存储已经反转的最后一个节点和当前要反转的节点。

然后内部就用反转列表的方法来进行反转，反转完后在进行拼接。拼接完后要更新当前反转列表的最后一个节点，以及未反转列表的第一个节点。


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
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0,head);
        
        ListNode curr = head;
        ListNode curLast = null;
        ListNode prevLast = dummy;
        ListNode temp = null;
        ListNode prev = null;
        int num;
        
        while(curr != null){
            num = 0;
            ListNode reverse = curr;
            while(num <k && reverse != null){
                reverse = reverse.next;
                num++;
            }
            
            if(num != k){
                prevLast.next = curr;
                return dummy.next;
            }
            
            num = 0;
            curLast = curr;
            prev = null;
            while(num < k){
                temp = curr.next;
                curr.next=prev;
                prev = curr;
                curr = temp;
                num ++;
            }
            
            prevLast.next = prev;
            prevLast = curLast;
        }
        return dummy.next;
    }
}
```