class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        
        unordered_map<string, int> bag;
        
        for(int i = 0; i < words.size(); i++) {
            bag[words[i]]++;
        }
        
        for(const auto& it: bag) {
            string curWord = it.first;
            
            int curIdx = 0;
            
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == curWord[curIdx]) {
                    curIdx++;
                }
                
                if(curIdx == curWord.size()) {
                    count+= it.second;
                    break;
                }
            }
        }
        
        return count;
           
    }
};