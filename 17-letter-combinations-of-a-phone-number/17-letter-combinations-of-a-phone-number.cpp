class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        
        if(digits.empty()) {
            return output;
        }
        
        unordered_map<char,string> pad;
        pad['1'] = "";
        pad['2'] = "abc";
        pad['3'] = "def";
        pad['4'] = "ghi";
        pad['5'] = "jkl";
        pad['6'] = "mno";
        pad['7'] = "pqrs";
        pad['8'] = "tuv";
        pad['9'] = "wxyz";
        
        output.push_back("");
        
        for(char& digit : digits) {
            vector<string> temp;
            for(char& letter : pad[digit]) {
                for(string& combination : output) {
                    temp.push_back(combination + letter);
                }
            }
            output.swap(temp);
        }
        
        return output;
    }
};