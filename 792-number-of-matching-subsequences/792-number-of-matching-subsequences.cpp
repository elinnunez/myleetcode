class Solution {
public:
    bool isMatch(string &s, string curWord) {
        int curI = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == curWord[curI]) {
                curI++;
            }

            if(curI == curWord.size()) {
                return true;
            }
        }
        
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<string, int> bag;
        
        for(int i = 0; i < words.size(); i++) { // O(n)
            bag[words[i]]++;
        }
        
        int count = 0;
        
        // O(n^2)
        for(const auto& it: bag) { // O(n)
            
            if(isMatch(s, it.first)) { // O(n)
                count+= it.second;
            }
            
        }
        
        return count;
        
    }
};

// Time Complexity: O(n+n^2) = O(n^2)