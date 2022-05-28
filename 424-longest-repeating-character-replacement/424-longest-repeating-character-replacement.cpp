class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        
        int maxLength = 0;
        
        int maxRepeat = 0;
        
        int left = 0;
        
        for(int i = 0; i < s.size(); i++) {
            char curChar = s[i];
            
            hash[curChar]++;
            
            maxRepeat = max(maxRepeat, hash[curChar]);
            
            if ((i - left + 1 - maxRepeat) > k) {
                char leftChar = s[left];
                hash[leftChar]--;
                left++;
            }
            
            maxLength = max(maxLength, i - left + 1);
                
        }
        
        return maxLength;
        
    }
};