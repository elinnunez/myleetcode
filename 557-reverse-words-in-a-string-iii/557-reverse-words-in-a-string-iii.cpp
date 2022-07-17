class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        string delimiter = " ";
        size_t pos = 0;
        string token;
        
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            reverse(token.begin(), token.end());
            output+= token + " ";
            s.erase(0, pos + delimiter.length());
        }
        reverse(s.begin(), s.end());
        output+= s;
        
        return output;
        
    }
};