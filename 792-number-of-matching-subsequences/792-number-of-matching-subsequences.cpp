class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<string, int> bag;
        
        for(int i = 0; i < words.size(); i++) { // O(n)
            bag[words[i]]++;
        }
        
        int count = 0;
        
        // O(n^2)
        for(const auto& it: bag) { // O(n)
            string curWord = it.first;
            
            int curI = 0;
            
            for(int i = 0; i < s.size(); i++) { // O(n)
                if(s[i] == curWord[curI]) {
                    curI++;
                }
                
                if(curI == curWord.size()) {
                    count+= it.second;
                    break;
                }
            }
        }
        
        return count;
        
    }
};

// Time Complexity: O(n+n^2) = O(n^2)