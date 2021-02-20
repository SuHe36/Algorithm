132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.



## 思路
给与一个字符串，将它进行切分，使得切分的每一部分都是一个回文串，求最少的切分次数。

用动态规划做，如果s[j:i]是回文串的话，dp[i]=Math.min(dp[i], dp[j-1]+1)



```
class Solution {
    public int minCut(String s) {
        
        int n = s.length();
        
        if(n==0 || n==1){
            return 0;
        }
        
     
        
        boolean[][] p = new boolean[n][n];
        
        for (int i=0; i<n;i++){
            // p[i][i] = true;
            for(int j=0;j<=i;j++){
                if(s.charAt(i)==s.charAt(j) &&(i-j <=2 || p[j+1][i-1]==true)){
                    p[j][i] = true;
                }
            }
        }
        
        int[] dp = new int[n];
        
        for(int i=1; i<n;i++){
            dp[i] = i;
        // 注意这里dp[i]的取值，是i，不是i-1
            for(int j=0; j<=i;j++){
                if(p[j][i]){
                    dp[i] = j ==0 ? 0: Math.min(dp[i],dp[j-1]+1);
                }
            }
        }
        
        return dp[n-1];
        
        
    }
}

```
