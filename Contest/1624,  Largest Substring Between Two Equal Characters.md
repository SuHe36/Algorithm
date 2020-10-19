1624,  Largest Substring Between Two Equal Characters


Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
Example 4:

Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".



思路：找到两个字符间的最大长度

代码：
```
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        if len(s) == 0:
            return -1;
        
        res = -1;
        d = dict()
        for i in range(len(s)):
            char = s[i]
            if char in d.keys():
                res = max(res, i-d[char]-1)
            else:
                d[char] = i
                
        return res
```