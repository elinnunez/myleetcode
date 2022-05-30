class Solution {
public:
    string minWindow(string s, string t) {
        
        string out = "";
        
        if(t.size() > s.size()) {
            return out;
        }
        
        unordered_map<char,int> hash;
        
        int left = 0;
        
        int matches = 0;
        
        for(const auto& it: t) {
            hash[it]++;
        }
        
        for(int r = 0; r < s.size(); r++) {
            char curChar = s[r];
            
            if(string(1, curChar) == t) {
                return t;
            }
            
            if(hash.count(curChar)) {
                hash[curChar]--;
                if(hash[curChar] >= 0) {
                    matches++;
                }
            }
            
            // cout << "matches: " << matches << endl;
            
            while(matches == t.size()) {
                string temp = s.substr(left, r - left + 1);
                
                // cout << "temp: " << temp << endl;
                
                if(temp.size() < out.size() || out == "") {
                    out = temp;
                }
                
                
                // cout << "out: " << out << endl;
                
                // while (left <= r && matches == t.size()) {
                // string curStr = s.substr(left, r+1);
                // cout << "curStr: " << curStr << endl;
                
                // out = curStr;
                
                char leftChar = s[left];
                
                if(hash.count(leftChar)) {
                    if(hash[leftChar] == 0) {
                        matches--;
                    }
                    hash[leftChar]++;
                }
                    
                left++;
            // }
                
            }
            
            
            // cout << "matches: " << matches;
        }
        
//         matches+=1;
        
//         int r = out.size()-1;
        
//         cout << "matches: " << matches << " vs t.size(): " << t.size() << endl;
        
//         while(matches == t.size()) {
//             string curStr = out.substr(0, r+1);
//             cout << "curStr: " << curStr << endl;
            
//             out = curStr;
            
//             char rightChar = out[r];
            
//             if(hash.count(rightChar)) {
//                 break;
//             }
            
//             r--;
            
//         }
        
        return out;
        
    }
};