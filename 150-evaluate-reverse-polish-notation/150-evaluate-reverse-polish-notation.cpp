class Solution {
public:
    int operations(int a, int b, string c) {
        int res;
        
        if (c == "+") {
            res = a + b;
        } else if (c == "-") {
            res = b - a;
        } else if (c == "*") {
            res = a * b;
        } else {
            res = b / a;
        }
        
        return res;
    }
    
    bool isNumber(string s) {
        if (s == "-" || s == "+" || s == "*" || s == "/") {
            return false;
        }
        return true;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> bag;
        
        for(int i = 0; i < tokens.size(); i++) {
            string cur = tokens[i];
            if(isNumber(cur) == false) {
                int a = bag.top();
                bag.pop();
                
                int b = bag.top();
                bag.pop();
                
                int result = operations(a,b,cur);
                bag.push(result);
            } else {
                bag.push(stoi(cur));
            }
        }
        
        return bag.top();
    }
};