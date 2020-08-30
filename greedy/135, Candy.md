135. Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.



思路：因为这个对当前位置i的元素，有左右两个方向的要求，所以考虑遍历数组两次，一次从前往后，保证当前位置的的右边符合规则，一次从后往前，保证当前位置的左边符合规则。

代码如下：
```
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if(n==0 || n==1){
            return n;
        }
        
        int[] nums = new int[n];
        Arrays.fill(nums,1);
        
        for(int i=0; i<n-1;i++){
            if(ratings[i] < ratings[i+1]){
                nums[i+1] = nums[i] + 1;
            }
        }
        
        for(int j=n-1; j>0;j--){
            if(ratings[j] < ratings[j-1]){
                nums[j-1] = Math.max(nums[j-1], nums[j]+1);
            }
        }
        return Arrays.stream(nums).sum();
    }
}
```