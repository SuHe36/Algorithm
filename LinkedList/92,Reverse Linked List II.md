92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

思路：从中间的一个节点进行反转，需要考虑头结点就开始反转的问题

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null){
            return null;
        }
        
        ListNode dummy = new ListNode(0,head);
        ListNode prev = dummy;
        ListNode curr = head;
        int num = 1;
        while(num < m){
            prev = curr;
            curr = curr.next;
            num +=1;
        }
        
        ListNode temp;
        ListNode reverseFirst = curr;
        ListNode tmp_prev = null;
        while(num <= n){
            temp = curr.next;
            curr.next = tmp_prev;
            tmp_prev = curr;
            curr = temp;
            num += 1;
        }
        prev.next = tmp_prev;
        reverseFirst.next = curr;
        return dummy.next;
    }
}
```