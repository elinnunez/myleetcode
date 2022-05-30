class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> hash;
        
        vector<int> out;
        
        int matches = 0;
        int left = 0;
        
        for(const auto& it: p) {
            hash[it]++;
        }
        
        for(int r = 0; r < s.size(); r++) {
            char curChar = s[r];
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] == 0) {
                    matches++;
                }
            }
            
            if(matches == hash.size()) {
                out.push_back(left);
            }
            
            if(r >= p.size() - 1) {
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