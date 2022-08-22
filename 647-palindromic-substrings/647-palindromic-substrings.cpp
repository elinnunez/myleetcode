class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int left, right;
            left = right = i;
            
            //for odd length checking
            while(left >= 0 && s[left] == s[right] && right < s.size()) {
                count++;
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            
            //for even length checking
            while(left >= 0 && s[left] == s[right] && right < s.size()) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;

    }
};

// "aaa"
// i = 0, left = 0, right = 0, count = 0
// (1st condition)--> count = 1, left = -1, right = 1
// i = 0, left = 0, right = 1, count = 1
// (2nd condition)--> count = 2, left = -1, right = 2
// i = 1, left = 1, right = 1, count = 2
// (1st condition)--> count = 3, left = 0, right = 2
// (1st condition)--> count = 4, left = -1, right = 3
// i = 1, left = 1,  right = 2, count = 4
// (2nd condition)--> count = 5, left = 0, right = 3
// i = 2, left =  2, right = 2, count = 5
// (1st condition)--> count = 6, left = 1, right = 3
// i = 2, left = 2, right = 3
// skips 2nd condition since right not less than s.size
// return count = 6
