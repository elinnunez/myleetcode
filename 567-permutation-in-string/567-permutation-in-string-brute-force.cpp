class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int left = 0;
        
        sort(s1.begin(), s1.end()); // O(nlogn)
        
        for(int r = 0; r < s2.size(); r++) { // O(n)
            
            if(r - left == s1.size() - 1) {
                string temp = s2.substr(left, r-left+1);
                sort(temp.begin(), temp.end()); // O(nlogn)
                
                if(temp == s1) {
                    return true;
                }
                
                left++;
            }
        }
        
        return false;
        
    }
};

// Brute Force Solution
// Time Complexity: O(nlogn + n*(nlogn)) = O(n*nlogn)
