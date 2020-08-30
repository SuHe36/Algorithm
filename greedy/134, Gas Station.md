134. Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.



思路

首先想到的就是，对每个位置判断他们能否是起始点，起始点肯定要满足gas[i]>=cost[i]，时间复杂度为$O(n^2)$

代码：
```
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] diff = new int[n];
        int total = 0;
        for (int i =0; i<n;i++){
            diff[i] = gas[i] - cost[i];
            total += diff[i];
        }
        if(total <0){
            return -1;
        }
        
        for(int i = 0; i< n; i++){
            if(diff[i]>=0){
                boolean res = canCircle(i,diff,n);
                if(res == true){
                    return i;
                }
            }
        }
        return -1;
    }
    
    public boolean canCircle(int start, int[] diff, int n){
        int sum = 0;
        for (int i=start; i< n; i++){
            sum += diff[i];
            if(sum < 0){
                return false;
            }
        }
        
        for(int j=0; j < start; j++){
            sum += diff[j];
            if(sum <0){
                return false;
            }
        }
        return true;
    }
    
}
```


思路2：

显然$O(n^2)$的时间复杂度是需要进行优化的。

其实我们可以用sum[i]表示从0到i位置的gas[i]-cost[i]的累计和，也就是到达i位置油箱剩余的油量【可以为负数】。

我们可以证明，如果存在循环的话，那么sum[i]最小的点，就是我们起始点的上个位置。

证明：
首先要能跑通，那么sum[n-1]>=0肯定要成立，那么假设sum[i]是最小值点，那么从i+1到n-1中间的任意位置j的耗油量为sum[j]-sum[i]，

因为sum[i]是整个sum数组的最小值，所以sum[j]-sum[i] >=0；

所以此时从i+1到n-1位置是能跑通的。

那么从n-1位置跑到0在跑到i位置能否跑成功了，肯定也是能跑成功的。

假设跑到第j个(0=<j<i)位置，没跑成功，
那么也就是从i+1跑到n-1在跑到j没成功，也就是sum[n-1]-sum[i] + sum[j] < 0，
即sum[n-1] + (sum[j] - sum[i]) < 0，因为sum[n-1] >=0, 所以sum[j] - sum[i] <0。
这与我们假设sum[i]是整个sum数组的最小值相矛盾，所以不存在从i+1到n-1跑通，再从0开始跑到i时跑不通的情况。

代码如下：
```
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int sum = 0;
        int min_sum = 0;
        int min_index = -1; 
        for (int i=0; i<n;i++){
            sum += gas[i] - cost[i];
            if(sum < min_sum){
                min_sum = sum;
                min_index = i;
            }
        }

        return sum <0? -1:min_index+1;
        
      
    }    
}
```
