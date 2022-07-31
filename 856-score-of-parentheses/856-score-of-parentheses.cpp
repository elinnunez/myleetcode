class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> stk;
        
        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];
            if(s[i] == '(') {
                stk.push(score);
                score = 0;    
            } else {
                score = stk.top() + max(2*score,1);
                stk.pop();
            }
        }
        
        return score;
    }
};

// "()(()())", score = 0, stk = []
// s[0] = (, stk = [0], score = 0
// s[1] = ), score = 0 + max(0,1) = 1, stk = []
// s[2] = (, stk = [1], score = 0
// s[3] = (, stk = [1,0], score = 0
// s[4] = ), score = 0 + max(0,1) = 1, stk = [1]
// s[5] = (, stk = [1,1], score = 0
// s[6] = ), score = 1 + max(0,1) = 2, stk = [1]
// s[7] = ), score = 1 + max(4,1) = 5, stk = []

// Time Complexity: O(n)
// Space Complexity: O(n)