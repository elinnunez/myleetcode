class Solution {
public:
    void reverseIt(vector<char>& s, int i, int j) {
        if(i >= j) {
            return;
        } else {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
            reverseIt(s,i,j);
        }
        return;
    }
    
    void reverseString(vector<char>& s) {
        
        reverseIt(s,0,s.size()-1);
    }
};