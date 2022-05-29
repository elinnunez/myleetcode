class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int left = 0;
        
        unordered_map<char,int> hash;
        
        for(int i = 0; i < s1.size(); i++) {
            hash[s1[i]]++;
        }
        
        int matches = 0;
        
        for(int r = 0; r < s2.size(); r++) {
            char curChar = s2[r];
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] == 0) {
                    matches++;
                }
            }
            
            if(matches == hash.size()) {
                return true;
            }
            
            if(r >= s1.size() - 1) {
                char leftChar = s2[left];
                
                if(hash.count(leftChar)) {
                    if(hash[leftChar] == 0) {
                        matches--;
                    }
                    hash[leftChar]++;
                }
                left++;
            }
            
        }
        
        return false;
        
    }
};


// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
        
//         int left = 0;
        
//         sort(s1.begin(), s1.end()); // O(nlogn)
        
//         for(int r = 0; r < s2.size(); r++) { // O(n)
            
//             if(r - left == s1.size() - 1) {
//                 string temp = s2.substr(left, r-left+1);
//                 sort(temp.begin(), temp.end()); // O(nlogn)
                
//                 if(temp == s1) {
//                     return true;
//                 }
                
//                 left++;
//             }
//         }
        
//         return false;
        
//     }
// };

// // Brute Force Solution
// // Time Complexity: O(nlogn + n*(nlogn)) = O(n*nlogn)