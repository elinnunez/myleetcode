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
        
        int curWin = INT_MAX; //  Set window to larget possible size
        
        for(const auto& it: t) {
            hash[it]++;
        }
        
        for(int r = 0; r < s.size(); r++) {
            char curChar = s[r];
            
            if(string(1, curChar) == t) { // if t is a single character and is found, that's the lowest that can be returned
                return t;
            }
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] >= 0) {
                    matches++;
                }
            }
            
            while(matches == t.size()) {
                
                int winSize = r-left+1; // current window size that has all matches
                
                if(winSize < curWin || out == "") { // check if the current winSize is smaller than previous curWin
                    out = s.substr(left, winSize); // output is now a smaller substring that still has all matches
                    curWin = winSize; // set curWin to newer smaller window size
                }
                
                char leftChar = s[left];
                
                if(hash.count(leftChar)) {
                    if(hash[leftChar] == 0) { // if the hash was emptied because of matches, decrement matches by 1 before putting left char back
                        matches--;
                    }
                    hash[leftChar]++; // return the count back to hash before incrementing left
                }
                    
                left++; // increment left by 1
            }
        }
        
        return out;
    }
};