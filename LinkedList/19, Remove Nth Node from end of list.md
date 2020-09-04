Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


思路：要删除链表中的倒数第n个的节点，那么我们可以设置快慢指针，一个fast先跑n步，一个slow后跑，他们之间的差值就是n。

这里有种特殊情况要处理，就是把头结点给删除了。这时直接返回head.next就可以了。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (n == 0){
            return head;
        }
        
        ListNode fast = head;
        ListNode slow = head;
        
        while(fast != null && n >0){
            fast = fast.next;
            n--;
        }
        if(fast == null){
            return head.next;
        }
        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}
```