class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        
        auto it = remove_if(s.begin(), s.end(), [](char const &c) {
            return !isalnum(c);
        });
 
        s.erase(it, s.end());
        
        int r = s.size() -1;
        
        while(l <= r) {
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            
            l++;
            r--;
        }
        
        return true;
    }                
};