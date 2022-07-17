class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> hash;
        
        for(int i = 0; i < s1.size(); i++) {
            hash[s1[i]]++;
        }
        
        int matches = 0;
        
        int left = 0;
        
        for(int r = 0; r < s2.size(); r++) {
            char curChar = s2[r];
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] == 0) {
                    matches++;
                }
            }
            
            if(matches == hash.size()) {
                return true;
            }
            
            if(r >= s1.size()-1) {
                char leftChar = s2[left];
                if(hash.count(leftChar)) {
                    if(hash[leftChar] == 0) {
                        matches--;
                    }
                    hash[leftChar]++;
                }
                left++;
            }
        }
        
        return false;
        
    }
};
