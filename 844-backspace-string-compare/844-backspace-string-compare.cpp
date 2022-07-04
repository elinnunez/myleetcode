class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> bag1;
        stack<char> bag2;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(bag1.empty()) {
                    continue;
                } else {
                    bag1.pop();   
                }
            } else {
                bag1.push(s[i]);
            }
        }
        
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '#') {
                if(bag2.empty()) {
                    continue;
                } else {
                    bag2.pop();   
                }
            } else {
                bag2.push(t[i]);
            }
        }
        
        string str1;
        string str2;
        
        while(!bag1.empty()) {
            str1+=bag1.top();
            bag1.pop();
        }
        
        while(!bag2.empty()) {
            str2+=bag2.top();
            bag2.pop();
        }
        
        return str1 == str2;
        
    }
};