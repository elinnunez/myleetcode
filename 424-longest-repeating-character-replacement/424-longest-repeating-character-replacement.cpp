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


// s = "ABAB" k = 2: left = 0; maxLength = 0; maxRepeat = 0;
// i = 0; curchar = A; hash[A] = 1; maxRepeat = max(0,1) =  1; maxLength = max(0, 0 - 0 + 1) = 1; left = 0;
//    if((0 - 0 + 1 - 1) -> 0 > 2)...
// i =  1; curChar = B; hash[B] = 1; maxRepeat = max(1,1) = 1; maxLength = max(1, 1- 0 + 1) = 2; left = 0;
//    if(1 - 0 + 1 - 1 -> 1 > 2)...
// i = 2; curChar = A; hash[A] = 2, maxRepeat = max(1,2) = 2; maxLength = max(2, 2 - 0 + 1) = 3; left = 0;
//    if(2 - 0 + 1 - 2 -> 1 > 2)
// i = 3; curChar = B; hash[B] = 2; maxRepeat = max(2, 2) = 2; maxLength = max(3, 3 - 0 + 1) = 4; left = 0;
//    if(3 - 1 + 1 - 2 -> 1 > 2)...
