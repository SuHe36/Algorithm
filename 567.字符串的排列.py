#
# @lc app=leetcode.cn id=567 lang=python3
#
# [567] 字符串的排列
#
# https://leetcode-cn.com/problems/permutation-in-string/description/
#
# algorithms
# Medium (37.88%)
# Likes:    206
# Dislikes: 0
# Total Accepted:    49K
# Total Submissions: 129.3K
# Testcase Example:  '"ab"\n"eidbaooo"'
#
# 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
# 
# 换句话说，第一个字符串的排列之一是第二个字符串的子串。
# 
# 示例1:
# 
# 
# 输入: s1 = "ab" s2 = "eidbaooo"
# 输出: True
# 解释: s2 包含 s1 的排列之一 ("ba").
# 
# 
# 
# 
# 示例2:
# 
# 
# 输入: s1= "ab" s2 = "eidboaoo"
# 输出: False
# 
# 
# 
# 
# 注意：
# 
# 
# 输入的字符串只包含小写字母
# 两个字符串的长度都在 [1, 10,000] 之间
# 
# 
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        self.res = []
        l = list(s1)
        self.dfs(l,[])

        for s in self.res:
            if s in s2:
                return True 
        return False 

    def dfs(self, s, ans):
        if not s:
            self.res.append("".join(ans))
            return

        for i in range(len(s)):
            char = s.pop(i)
            self.dfs(s, ans+[char])
            s.insert(i, char)
        
        return


# @lc code=end

