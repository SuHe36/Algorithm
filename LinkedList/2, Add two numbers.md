You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


思路：用一个prev和curr分别指向前节点和当前节点。

这里的处理是使用了一个虚假的头节点，用来存储链表的开头，其中prev要指向虚假的头节点，而curr需要指向链表的真实的第一个节点，并且prev.next=curr这个关系需要在循环里面确定。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        ListNode curr = null;
        int sum = 0;
        
        while(l1 != null || l2 != null){
            int num1 = l1 == null? 0: l1.val;
            int num2 = l2 == null? 0: l2.val;
            
            sum = sum + num1 + num2;
            curr = l1 != null ? l1 : l2;
            curr.val = sum %10;
            sum = sum /10;
            prev.next = curr;
            prev = curr;
            l1 = l1 == null? null:l1.next;
            l2 = l2 == null? null:l2.next;
            
        } 
        
        if(sum != 0 ){
            prev.next = new ListNode(sum);
        }
        return dummy.next;
    }
}
```