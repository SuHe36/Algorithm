321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]


思路：

我们已经知道一个数组如何选取k位组成最大的数，那么两个数组如何组成最大的数，可以由每一个单一数组先分别组成最大数，在合并。

遍历所有情况，保存最大的数就可以。

这道题，最恶心的是合并的两个最大数组，形成新的最大数时。有可能两个数组中的数是相同的，这时需要看他们下一位哪个大，选择下一位大的那个作为当前的数。这里面还有一种极端情况，就是当a数组遍历完了，还是和b数组每一位都是相同的，那么此时认为，谁先遍历完谁小。仔细思考，如果选择先遍历完的a数组作为大的话，那么会先把这个短数组a遍历完，遍历完后，只能从长数组b的相等的那个位置再往后遍历，如果b数组长出来的那部分，是一个大数，显然不应该把它放在最后面。所以为了避免这种情况，我们要认为短数组是小的。


代码：
```
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        
        int[] ans = new int[nums1.length + nums2.length];
        
       
        for(int j=0;j <= k; j++){
            if(j > nums1.length || k-j > nums2.length){
                continue;
            }
            // System.out.println("j is:"+j);
            int[] res1 = getMaxNumber(nums1,nums1.length-j);
            int[] res2 = getMaxNumber(nums2, nums2.length-k+j);
            int[] m = merge(res1, res2);
            boolean f = isBigger(m, ans);
            // System.out.println("m:"+Arrays.toString(m) +"\nans:"+Arrays.toString(ans) + "\nf:"+f +"\n\n");

            if(f){
                ans = m;
            }

        }
        return ans;
        
    }
    
    public boolean isBigger(int[] nums, int[] max){
        int i =0;
        while(i < nums.length){
            if(nums[i] > max[i]){
                // System.out.println("nums[i]:"+nums[i]+"\t ans[i]:"+max[i]);
                return true;
            }else if(nums[i] < max[i]){
                return false;
            }else{
                i++;
            }
        }
        return false;
      
    }
    
    public int[] merge(int[] n1, int[] n2){
        int[] r = new int[n1.length + n2.length];
        int i=0;
        int j=0;
        int ind =0;
        while(i<n1.length && j < n2.length){
            if(n1[i] > n2[j]){
                r[ind] = n1[i];
                i++;
                ind++;
            }else if(n1[i] < n2[j]){
                r[ind] = n2[j];
                j++;
                ind++;
            }else{
                boolean flag = compare(n1,i,n2,j);
                // System.out.println("i:"+i+"\t j:"+j+"\n flag:"+flag);
                if(flag){
                    r[ind] = n1[i];
                    i++;
                    ind++;
                }else{
                    r[ind] = n2[j];
                    j++;
                    ind++;
                }
              
            }
        }
        
        for(;i<n1.length;i++){
            r[ind] = n1[i];
            ind++;
        }
        
        for(int t=0;j<n2.length;j++){
            r[ind] = n2[j];
            ind++;
        }
        return r;
      
    }
    
    public boolean compare(int[] nums1, int start1, int[] nums2, int start2){
        int n1 = nums1.length;
        int n2 = nums2.length;
        while(start1 < n1 && start2 < n2){
            if(nums1[start1] < nums2[start2]){
                return false;
            } 
            if(nums1[start1] > nums2[start2]){
                return true;
            }
            start1++;
            start2++;
        }
        
        return start1==n1 ? false:true;
        
    }
    
    public int[] getMaxNumber(int[] nums, int t){
        int n = nums.length;
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<n;i++){
            while(stack.size()>0 && nums[i] > stack.peek() && t>0){
                stack.pop();
                t--;
            }
            stack.push(nums[i]);
        }
        while(t >0){
            stack.pop();
            t--;
        }
        
        int l = stack.size();
        int [] res = new int[l];
        for(int i=l-1; i>=0;i--){
            res[i] = stack.pop();
        }
        // System.out.println("nums:"+Arrays.toString(nums)+"\n t:" + t+"\nres:"+Arrays.toString(res) +"\n" );
        return res;
    }
}
```