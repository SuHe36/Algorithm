55. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5

思路：不断记录当前能够跳到的最大位置，如果遍历的下标，大于记录的最大位置，说明存在一个断层。

这个贪心是不断记录能达到的最远位置。


```
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if (n==0){
            return false;
        }
        
        int maxpos = 0;
        for(int i =0; i<n; i++){
            if(i > maxpos){
                return false;
            }
            maxpos = Math.max(maxpos, i+nums[i]);
        }
        return true;
    }
}
```



45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

思路：这个是要求能用最短的跳跃到达最后位置，所以我们可以存储每一次能够到达的最远位置，
然后从第k次起跳点和最远位置之间遍历，找到第k+1次起跳能到达的最远位置。

那么第k+1次，遍历的起点就是第k次的最远位置+1，终点就是第K+1词能够到达的最远点。

这个贪心，是每次起跳都要找到能跳的最远点。

代码：
```
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n==1){
            return 0;
        }
        int maxpos = nums[0];
        int step = 1;
        int start = 1;
        while (maxpos < n-1){
            int curmax = maxpos;
            for(int i =start; i<= maxpos;i++ ){
                curmax = Math.max(curmax, i+nums[i]);
            }
            step += 1;
            start = maxpos+1;
            maxpos = curmax;
        }
            
        return step;
            
    }
}
```
