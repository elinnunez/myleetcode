class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> ht;
        
        for(char& c : s) {
            ht[c]++;
        }
        
        for(char& c : t) {
            if(ht.count(c)) {
                ht[c]--;
                if(ht[c] == 0) {
                    ht.erase(c);
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
};