83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

思路：从一个排好序的listNodes里，删除重复的元素，遍历一次就可以实现。

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode curr = head;
        ListNode diff = null;
        while(curr != null){
            diff = curr.next;
            while(diff != null && diff.val == curr.val){
                diff = diff.next;
            }
            curr.next = diff;
            curr = diff;
        }
        return head;
    }
}
```