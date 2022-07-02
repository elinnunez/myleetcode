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
            string curChar = tokens[i];
            if(isNumber(curChar) == false) {
                int a = bag.top();
                bag.pop();
                int b = bag.top();
                bag.pop();
                int c = operations(a,b,curChar);
                bag.push(c);
            } else {
                bag.push(stoi(curChar));
            }
        }
        
        return bag.top();
    }
};