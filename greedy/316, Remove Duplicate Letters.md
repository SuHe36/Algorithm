316. Remove Duplicate Letters


Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"
Example 2:

Input: "cbacdcbc"
Output: "acdb"

思路： 

这个是要求最后返回的字符串不包含重复的，并且字典序最小，那么他们的比较就是出现多次的字符之间自生的比较，用来确定哪个位置的字符留下来。那么我们首先需要直到每个字符最后出现的位置，用来决定当前字符能不能删除。

同时，我们可以用一个栈来存储已经保留下来的字符，然后如果当前字符比栈顶元素小，并且栈顶元素不是该元素的最后一个位置，那么栈顶元素就可以出栈（删除）。


代码：
```
class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] ind = new int[26];
        for (int i=0; i<n;i++){
            ind[s.charAt(i)-'a'] = i;
        }
        Set<Character> seen = new HashSet<>();
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<n;i++){
            Character c = s.charAt(i);
            if(!seen.contains(c)){
                while(stack.size()>0 && c < stack.peek() 
                  && ind[stack.peek()-'a'] >i ){
                    Character p = stack.pop();
                    seen.remove(p);
                
                }
                seen.add(c);
                stack.push(c);         
            }

        }
        
        StringBuilder sb = new StringBuilder();
        while(stack.size()>0){
            sb.insert(0,stack.pop());
        }
        return sb.toString();
    }
}
```