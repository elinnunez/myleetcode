class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> temp;
        
        unordered_map<string, vector<string>> ht;
        
        for(string const& word : strs) {
            string temp = word;
            sort(begin(temp),end(temp));
            ht[temp].push_back(word);
        }
        
        for(auto const& it : ht) {
            temp.push_back(it.second);
        }
        
        return temp;
        
    }
};