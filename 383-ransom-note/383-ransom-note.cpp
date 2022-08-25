class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) {
            return false;
        }
        
        unordered_map<char,int> ht;
        
        for(const auto& c : magazine) {
            ht[c]++;
        }
        
        for(const auto& c : ransomNote) {
            if(!ht.count(c)) {
                return false;
            } else {
                ht[c]--;
                if(ht[c] == 0) {
                    ht.erase(c);
                }
            }
        }
        
        return true;
    }
};