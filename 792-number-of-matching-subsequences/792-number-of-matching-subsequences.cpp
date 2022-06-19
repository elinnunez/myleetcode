class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<string, int> bag;
        
        for(int i = 0; i < words.size(); i++) {
            bag[words[i]]++;
        }
        
        int count = 0;
        
        for(const auto& it: bag) {
            string curWord = it.first;
            
            int curI = 0;
            
            for(int i = 0; i < s.size(); i++) {
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