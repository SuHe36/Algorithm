24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

思路： 用first和second来指代第一个和第二个node，然后控制一个prev节点来不断链接整个链表。

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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        ListNode first = head;
        ListNode second = null;
        
        while(first != null){
            if(first.next == null){
                break;
            }
            
            second = first.next;
            first.next = second.next;
            second.next = first;
            prev.next = second;
            prev = first;
            first = first.next;
        }
        return dummy.next;
    }
}
```