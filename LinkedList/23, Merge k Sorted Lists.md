23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.


思路：对k个序列进行合并，显然使用最小堆每次选取最小的元素，就可以了。

这道题主要注意使用优先队列`PriorityQueue`来实现最小堆和最大堆的区别。

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
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        if(n== 0){
            return null;
        }
        Queue<ListNode> priorityQueue = new PriorityQueue<ListNode>(n, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode l1, ListNode l2){
//           l1表示排在前面的数，l2表示排在后面的数
//          如果l1.val < l2.val，值为负，false,表示不需要调整顺序，也就是升序，
//          如果la.val > l2.val，值为正,true,表示需要调整顺序，也是升序
//            如果想实现降序，返回l2.val -l1.val就可以
                return l1.val - l2.val;
            }
        });
        
        for (int i=0; i<n;i++){
            if(lists[i] == null){
                continue;
            }
            priorityQueue.add(lists[i]);
        }
        
        ListNode dummy = new ListNode(0);
        ListNode head = dummy;
        
        while(priorityQueue.size() != 0){
            ListNode curr = priorityQueue.poll();
            head.next = curr;
            head = head.next;
            if(curr.next != null){
                priorityQueue.add(curr.next);
            }
        }
        
        return dummy.next;
    }
}
```