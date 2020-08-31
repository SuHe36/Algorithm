402. Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


思路：

总体思路就是，当前位置的值和它左边的值进行比较，如果当前值大于左边的值，直接拼接在后面，如果当前值小于左边的值，就把左边的值删除，删除后要继续和左边的值进行比较。

主要是因为，数字123a456和123b456，如果a>b，那么123a456 > 123b456,也就是说，**两个相同位数的数字的大小，取决于第一个不相等的数字的大小**。

具体的思路就是单调栈的思想，用一个栈来存储一个单调递增的结构，但是由于我们最后要组成数字，所以要从前往后取，所以我们可以构造双向队列。

注意这题里的双向队列的一些接口的调用，以及StringBuilder使用append()接口等。

代码：
```
class Solution {
    public String removeKdigits(String num, int k) {
        int n = num.length();
        Deque<Character> deque = new LinkedList<>();
        
        int i = 0;
        while(i<n){
            char c = num.charAt(i);
            while(!deque.isEmpty() && k>0 && deque.getLast()> c){
                deque.removeLast();
                k--;
            }
            deque.addLast(c);
            i++;
        }
        while(k>0 && deque.size() >0){
            deque.removeLast();
            k--;
        }

        while(deque.size()>0 && deque.getFirst()=='0'){
            deque.removeFirst();
        }

        if(deque.isEmpty()){
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        int len = deque.size();
        for(int j=0; j<len;j++){
            sb.append(deque.removeFirst());
        }
        
        return sb.toString();

        
    }
}
```