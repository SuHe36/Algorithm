435. Non-overlapping Intervals
    
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.


思路：采取贪心的方法来做，先对这个二维数组按照结束点进行排序，这里注意java8的新排序方法。

然后贪心的主要思路就是，每次找到的不重叠的end点都是最靠前的，那样可以留下更多地空间给剩余的地方。

代码：
```
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length==0){
            return 0;
        }
        
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[1],b[1]));
        
        int remove = 0;
        int end = intervals[0][1];
        int n = intervals.length;
        
        for(int i=1; i<n; i++){
            if(intervals[i][0]<end){
                remove += 1;
            }else{
                end = intervals[i][1];
            }
        }
        return remove;
    }
}
```