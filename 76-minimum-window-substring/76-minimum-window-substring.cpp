class Solution {
public:
    string minWindow(string s, string t) {
        
        string out = "";
        
        if(t.size() > s.size()) {
            return out;
        }
        
        unordered_map<char,int> hash;
        
        int left = 0;
        
        int matches = 0;
        
        int curWin = INT_MAX;
        
        for(const auto& it: t) {
            hash[it]++;
        }
        
        for(int r = 0; r < s.size(); r++) {
            char curChar = s[r];
            
            if(string(1, curChar) == t) {
                return t;
            }
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] >= 0) {
                    matches++;
                }
            }
            
            while(matches == t.size()) {
                
                int winSize = r-left+1;
                
                if(winSize < curWin || out == "") {
                    out = s.substr(left, winSize);
                    curWin = winSize;
                }
                
                char leftChar = s[left];
                
                if(hash.count(leftChar)) {
                    if(hash[leftChar] == 0) {
                        matches--;
                    }
                    hash[leftChar]++;
                }
                    
                left++;
            }
        }
        
        return out;
    }
};