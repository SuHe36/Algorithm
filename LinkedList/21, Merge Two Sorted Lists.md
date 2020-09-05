21. Merge Two Sorted Lists


Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

思路：给定两个排序的链表，返回他们的合并的结果，那么我们可以使用一个dummy节点，和一个curr节点不断遍历两个链表，直到都为空退出。

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode head = dummy;
        
        while(l1 != null || l2 != null){
            int p = l1 ==null ? Integer.MAX_VALUE:l1.val;
            int q = l2 ==null ? Integer.MAX_VALUE:l2.val;
            
            if(p < q){
                head.next = l1;
                l1 = l1.next;
            }else{
                head.next = l2;
                l2 = l2.next;
            }
            
            head = head.next;
        }
        return dummy.next;
    }
}
```