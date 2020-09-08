82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3


思路：这题是要对排序链表进行删除，但是删除时不保留任何存在重复值的元素，

所以这题与83题的不同是，83题删除元素时还会保留一个值。

所以这题的处理方法就是，对于任何的curr.next.val == curr.val的节点，都不先接入prev.next的后面。

代码如下：
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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode curr = head;
        while(curr != null){
            if(curr.next != null && curr.next.val == curr.val){
                while(curr.next != null && curr.next.val == curr.val){
                    curr = curr.next;
                }
                if(curr.next == null){
                    prev.next = null;
                    return dummy.next;
                }
                curr = curr.next;
            }else{   
                prev.next = curr;
                prev = curr;
                curr = curr.next;
            }
        }
        return dummy.next;
    }
}
```