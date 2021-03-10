实现建堆的核心思想是，从底部往上走，用dfs。

具体代码如下：
```
class Solution:
    def heap(self, nums):
        for i in range(len(nums)//2, -1, -1):
            print(i)
            self.dfs(nums, i)
            print(nums)
        return nums
    def dfs(self, nums, pid):
        mid = pid
        lid,rid = 2*pid+1, 2*pid+2
        
        if lid < len(nums) and nums[lid] > nums[mid]:
            mid = lid
        
        if rid < len(nums) and nums[rid] > nums[mid]:
            mid = rid
        
        if mid != pid:
            temp = nums[mid]
            nums[mid] = nums[pid]
            nums[pid] = temp
            self.dfs(nums, mid)
        return
            
```