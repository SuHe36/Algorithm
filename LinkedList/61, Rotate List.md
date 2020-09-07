61. Rotate List


Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

思路：对一个list从中间进行旋转，其实就是将后半段接在前半段之前，所以需要找到分割点。

这里需要先判断k是否大于整个list的长度，如果大于整个list的长度，那么就需要对k进行取余操作。

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return null;
        }
        ListNode last = head;
        int num = 1;
        while(last.next != null){
            num += 1;
            last = last.next;
        }
        
        k = k%num;
        k = num - k;
        ListNode curr = head;
        int start = 1;
        while(start < k){
            curr = curr.next;
            start += 1;
        }
        last.next = head;
        head = curr.next;
        curr.next = null;
        
        return head;
        
    }
}
```