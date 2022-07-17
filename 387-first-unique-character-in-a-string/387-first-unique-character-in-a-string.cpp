class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,bool> unique;
        
        for(int i = 0; i < s.size(); i++) {
            if(!unique.count(s[i])) {
                unique[s[i]] = true;
            } else {
                unique[s[i]] = false;
            }
        }
        
        int firstUnique = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(unique[s[i]] == true) {
                return i;
            }
        }
        
        return firstUnique;
    }
};