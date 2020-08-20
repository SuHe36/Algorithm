Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]



思路：
我们首先想到用回溯算法来做。

常规的回溯算法如下：
```
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        
        int n = s.length();
        
        List<String> temp = new ArrayList<>();
        List<List<String>> res = new ArrayList<>();
        Helper(s, wordDict, n,0,temp,res);
        
        List<String> ans =  new ArrayList<>();
        
        
        for(List<String> t: res){
            String s1 = "";
            for(String s2: t){
                s1 = s1 + " " + s2;
            }
            ans.add(s1.trim());
        }
        
        return ans;
    }
    
    public void Helper(String s, List<String> wordDict, int n, int start,
                      List<String> temp, List<List<String>> res){
        
        if (start == n){
            res.add(new ArrayList<>(temp));
        }
            
        for(int i=start; i<n; i++){
            if(wordDict.contains(s.substring(start, i+1))){
                temp.add(s.substring(start, i+1));
                Helper(s, wordDict, n,i+1,temp,res );
                temp.remove(temp.size()-1);
            }
        }
        
    }
}
```

这种思路，对于这个case一直超时：
`Last executed input:
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]`

主要是因为这个dict里面得词都很相似，所以其实后续的回溯计算中，有很多重复的操作。

所以可以考虑，把后面的所有操作结果都缓存下来，加速。
实验代码如下：

```
class Solution {
    Map<Integer, List<String>> map = new HashMap<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
              
        
        dfs(s, wordDict, 0);
        return map.get(0);
        
    }
    
    public List<String> dfs(String s, List<String> wordDict, int start){
        List<String> res = new ArrayList<>();
        if(start == s.length()){
            res.add("");
        }
        
        if(map.containsKey(start)){
            return map.get(start);
        }
        //用一个map存储每个位置的List<String>，注意这种情况是没有temp.add()与temp.remove()的情况了
        //此时是遍历所有情况，然后把他们都存储下来，
        for(int end=start; end < s.length(); end++){
            if(wordDict.contains(s.substring(start, end+1))){
                List<String> list = dfs(s, wordDict, end+1);
                
                for(String l : list){
                    res.add(s.substring(start, end+1)+ (l.equals("")?"":" ") + l);
                }
                
            }
        }
        // System.out.println(start);
        // for(String t : res){
            // System.out.println(t);
        // }
        map.put(start, res);
        return res;
    }
   
   
}
```


思路三，采用动态规划的算法来做，dp[i] = dp[j] + s.substring(j,i+1) (for j in (0,i))

但是对于测试用例
Last executed input:
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]`
一样会报超时错误，代码如下：

```
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        if(n==0 || wordDict.size() == 0){
            return new ArrayList<>();
        }
        List<String>[] dp = new LinkedList[n+1];
    
        List<String> initial = new LinkedList<>();
        initial.add("");
        
        dp[0] = initial;
        
        for(int i =1;i<=n;i++){
            LinkedList<String> list = new LinkedList<>();
            for(int j=0; j<i; j++){
                //这里要判断dp[j]不为空
                if(dp[j] != null && dp[j].size()>0 && wordDict.contains(s.substring(j,i))){
                     for(String t : dp[j]){
                         list.add( t + (t.equals("")?"":" ") + s.substring(j,i));
                         //这里最好使用list来缓存，不能直接用dp[i]，因为dp[i]还未初始化
                    }
                }
                
            }
            dp[i] = list;
        }
        return dp[n];              
   
    }
    
}
```
