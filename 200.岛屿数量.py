#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
# https://leetcode-cn.com/problems/number-of-islands/description/
#
# algorithms
# Medium (51.39%)
# Likes:    913
# Dislikes: 0
# Total Accepted:    188.6K
# Total Submissions: 365.2K
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
# 
# 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
# 
# 此外，你可以假设该网格的四条边均被水包围。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：grid = [
# ⁠ ["1","1","1","1","0"],
# ⁠ ["1","1","0","1","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","0","0","0"]
# ]
# 输出：1
# 
# 
# 示例 2：
# 
# 
# 输入：grid = [
# ⁠ ["1","1","0","0","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","1","0","0"],
# ⁠ ["0","0","0","1","1"]
# ]
# 输出：3
# 
# 
# 
# 
# 提示：
# 
# 
# m == grid.length
# n == grid[i].length
# 1 
# grid[i][j] 的值为 '0' 或 '1'
# 
# 
#

# @lc code=start
class DSU:
    def __init__(self, N):
        self.p = [i for i in range(N)]

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xf = self.find(x)
        yf = self.find(y)
        if xf != yf:
            self.p[xf] = yf


    
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        dsu = DSU(m*n)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    for x, y in [[-1,0],[1,0],[0,-1],[0,1]]:
                        nx = i + x
                        ny = j + y
                        if 0<=nx < m and 0<= ny < n and grid[nx][ny] == '1':
                            dsu.union(i*n+j, nx*n+ny)

        res = set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    res.add(dsu.find(i*n+j))
        return len(res)
# @lc code=end

