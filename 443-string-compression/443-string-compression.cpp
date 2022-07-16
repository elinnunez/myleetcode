class Solution {
public:
    int compress(vector<char>& chars) {
        string output = "";
        
        for(int i = 0; i < chars.size(); i++) {
            char curChar = chars[i];
            
            int j = i;
            while(j < chars.size() && chars[j] == curChar) {
                j++;
            }
            
            int count = j-i;
            
            if(count == 1) {
                output+= curChar;
            } else {
                output+= curChar + to_string(count);
            }
            
            i = j-1;
        }
        
        for(int i = 0; i < output.size(); i++) {
            chars[i] = output[i];
        }
        
        return output.size();
        
    }
};