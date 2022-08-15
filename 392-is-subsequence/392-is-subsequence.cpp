class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size() == 0) {
            return true;
        }
        
        int sIdx = 0;
        
        for(int i = 0; i < t.size(); i++) {
            if(s[sIdx] == t[i]) {
                sIdx++;
            }
            
            if(sIdx == s.size()) {
                return true;
            }
        }
        
        return false;
        
    }
};