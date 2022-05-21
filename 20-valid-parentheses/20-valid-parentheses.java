class Solution {
    public boolean isValid(String s) {
        Stack<Character> temp = new Stack<Character>();
        
        for(int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            
            if(temp.empty()) {
                    temp.push(cur);
            } else {
                if(temp.peek() == '(' && cur == ')' || temp.peek() == '[' && cur == ']' || temp.peek() == '{' && cur == '}') {
                    temp.pop();
                } else {
                    temp.push(cur);
                }
                
            }
        }
        
        if(temp.empty()) {
            return true;
        }
        
        return false;
        
    }
}