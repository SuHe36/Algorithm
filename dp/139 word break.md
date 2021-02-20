139. Word Break



Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.


思路：
给与一个字符串和一个词典，判断当前字符串能否用词典切分。

用动态规划做,第i个字符，可以由(0,i-1)任意一个位置切割形成新的字符，然后用前面的字符组成新的结果。
dp[i] = dp[i]||(dp[j]&&s.substring(j,i+1)是否在dict中 )

代码：
```
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        
        int n = s.length();
        if(n==0){
            return false;
        }
        boolean[] dp = new boolean[n];
        
        for(int i=0; i<n;i++){
            for(int j=0; j<=i;j++){
                if(wordDict.contains(s.substring(j,i+1))){
                    dp[i] = (j==0? true : dp[j-1]) || dp[i];
                }
            }
        }
        
        return dp[n-1];
        
    }
}

```
