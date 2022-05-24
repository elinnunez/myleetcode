class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> temp;
        
        unordered_map<string, vector<string>> ht;
        
        for(int i = 0; i < strs.size(); i++) {
            string og = strs[i];
            
            sort(strs[i].begin(), strs[i].end());
            
            ht[strs[i]].push_back(og);
        }
        
        for(auto const& it : ht) {
            temp.push_back(it.second);
        }
        
        return temp;
        
    }
};