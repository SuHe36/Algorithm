86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。


思路：将一个链表中小于某个值的元素全部放在大于等于这个值的左边。

这题不用虚假头结点的代码：
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
    public ListNode partition(ListNode head, int x) {
        if(head == null){
            return null;
        }
        
        ListNode head_small = null;
        ListNode head_max = null;
        ListNode tail_small = null;
        ListNode tail_max = null;
        ListNode curr = head;
        while(curr != null){
            if(curr.val >= x){
                if(head_max == null){
                    head_max = curr;
                    tail_max = curr;
                }else{
                    tail_max.next = curr;
                    tail_max = tail_max.next;
                }
            }else{
                if(head_small == null){
                    head_small = curr;
                    tail_small = curr;
                }else{
                    tail_small.next = curr;
                    tail_small = tail_small.next;
                }
                
            }
            curr = curr.next;
        }
        
        if(tail_small == null){
            return head_max;
        }else{
            tail_small.next = head_max;
            if(tail_max != null){
                tail_max.next = null;
            }
            return head_small;
        }
    }
}
```



使用虚假头结点的代码：
```
public ListNode partition(ListNode head, int x) {
    ListNode dummy1 = new ListNode(0), dummy2 = new ListNode(0);  //dummy heads of the 1st and 2nd queues
    ListNode curr1 = dummy1, curr2 = dummy2;      //current tails of the two queues;
    while (head!=null){
        if (head.val<x) {
            curr1.next = head;
            curr1 = head;
        }else {
            curr2.next = head;
            curr2 = head;
        }
        head = head.next;
    }
    curr2.next = null;          //important! avoid cycle in linked list. otherwise u will get TLE.
    curr1.next = dummy2.next;
    return dummy1.next;
}
```