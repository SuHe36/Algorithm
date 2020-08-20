求最大连续子数组的乘积。

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

由于这里面有负数，而负负可以得正，所以除了要存储最大子数组值外，还需要存储最小子数组的值。
代码如下：
```
class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int[] max = new int[n];
        int[] min = new int[n];
        
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        max[0] = nums[0];
        min[0] = nums[0];
        int res = nums[0];
        
        for(int i=1; i<n; i++){
            max[i] = Math.max(nums[i], Math.max(nums[i]*max[i-1], nums[i]*min[i-1]));
            min[i] = Math.min(nums[i], Math.min(nums[i]*max[i-1], nums[i]*min[i-1]));
            res = Math.max(res, max[i]);
        }
        
        return res;
    }
}
```

显然，每个max[i]都只和前面的max[i-1]有关，并且每个min[i]都只和前面的min[i-1]有关，所以可以只用一个数不断缓存就行。

代码如下：
```
class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int max = nums[0];
        int min = nums[0];
        int res = nums[0];
        
        for(int i=1; i<n; i++){
            int temp_max = max;
            int temp_min = min;
            max = Math.max(nums[i], Math.max(nums[i]*temp_max, nums[i]*temp_min));
            min = Math.min(nums[i], Math.min(nums[i]*temp_max, nums[i]*temp_min));
            res = Math.max(res, max);
        }
        
        return res;
    }
}
```

