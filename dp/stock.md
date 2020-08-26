121. Best time to buy and sell stock I

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        
        if(n==0 || n==1){
            return 0;
        }
        
        
        int premin = prices[0];
        int gp = 0;
        
        for (int i = 1; i<n;i++){
            if(prices[i] < premin){
                premin = prices[i];
            }else{
                gp = Math.max(gp, prices[i]-premin);
            }
        }
        
        return gp;
        
    }
}
```

122. Best time to buy and sell stock II

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n==0 || n==1){
            return 0;
        }
        
        int[] dp = new int[n];
        dp[0] = 0;
        
        for(int i=1; i<n;i++){
            if(prices[i] >= prices[i-1]){
                dp[i] = dp[i-1] + prices[i] -prices[i-1];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
}
```

123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n==0 || n==1){
            return 0;
        }
//    递推公式是dp[k][i] = Max(dp[k][i-1], prices[i]-prices[j]+dp[k-1][j])(j=0,...,i-1)
//    也就是第i天第k次交易的最大利润，可以是第i-1天第k次交易，
//    也可以是第i天刚好完成第k次交易，其中在第i天卖出是固定的，但是可以在第j天买入的，j=0,...,i-1
        
        
        int[][] dp = new int[3][n];

        for(int k=1; k<=2; k++){
            for(int i=1; i<n;i++){
                int min = prices[0];
                for(int j=0; j<i;j++){
                    min = Math.min(min, prices[j]-dp[k-1][j]);
                }
                dp[k][i] = Math.max(dp[k][i-1], prices[i]-min);

            }
        }
        return dp[2][n-1];
    }
}
```

优化代码
```
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n==0 || n==1){
            return 0;
        }
//    递推公式是dp[k][i] = Max(dp[k][i-1], prices[i]-prices[j]+dp[k-1][j])(j=0,...,i-1)
//    也就是第i天第k次交易的最大利润，可以是第i-1天第k次交易，
//    也可以是第i天刚好完成第k次交易，其中在第i天卖出是固定的，但是可以在第j天买入的，j=0,...,i-1
        
        
        int[][] dp = new int[3][n];
// 其实min存的一直都是前i个中最小的那个，所以可以继续优化
        for(int k=1; k<=2; k++){
            int min = prices[0];
            for(int i=1; i<n;i++){
                
                min = Math.min(min, prices[i]-dp[k-1][i-1]);
                
                dp[k][i] = Math.max(dp[k][i-1], prices[i]-min);

            }
        }
        return dp[2][n-1];
    }
}
```



188. Best Time to Buy and Sell Stock IV

Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if(n==0 || n==1){
            return 0;
        }
//    递推公式是dp[k][i] = Max(dp[k][i-1], prices[i]-prices[j]+dp[k-1][j])(j=0,...,i-1)
//    也就是第i天第k次交易的最大利润，可以是第i-1天第k次交易，
//    也可以是第i天刚好完成第k次交易，其中在第i天卖出是固定的，但是可以在第j天买入的，j=0,...,i-1
        
        if(k > n/2){
            return quickSolve(prices);
        }
        
        int[][] dp = new int[k+1][n];
// 其实min存的一直都是前i个中最小的那个，所以可以继续优化
        for(int t=1; t<=k; t++){
            int min = prices[0];
            for(int i=1; i<n;i++){
                
                min = Math.min(min, prices[i]-dp[t-1][i-1]);
                
                dp[t][i] = Math.max(dp[t][i-1], prices[i]-min);

            }
        }
        return dp[k][n-1];
    }
    
    public int quickSolve(int[] prices){
        int len = prices.length;
        int profit = 0;
        for(int i=1; i< len; i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
}
```