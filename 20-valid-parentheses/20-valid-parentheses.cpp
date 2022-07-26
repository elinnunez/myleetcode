class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() < 2) {
            return false;
        }
        
        stack<char> temp;
        
        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];
            
            if(cur == '{' || cur == '[' || cur == '(') {
                temp.push(cur);
            } else {
                if(!temp.empty()) {
                    if(temp.top() == '(' && cur == ')' || temp.top() == '[' && cur == ']' || temp.top() == '{' && cur == '}') {
                        temp.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            
        }
        
        if(temp.empty()) {
            return true;
        }
        
        return false;
    }
};