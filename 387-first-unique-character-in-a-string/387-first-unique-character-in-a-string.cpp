class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,bool> unique;
        
        int firstUnique = -1;
        
        for(int i = s.size()-1; i >= 0; i--) {
            if(!unique.count(s[i])) {
                unique[s[i]] = true;
            } else {
                unique[s[i]] = false;
            }
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(unique[s[i]] == true) {
                firstUnique = i;
                break;
            }
        }
        
        return firstUnique;
    }
};