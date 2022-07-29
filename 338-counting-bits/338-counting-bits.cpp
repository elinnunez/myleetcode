class Solution {
public:
    int countBit(int n) {
        int count = 0;
        while(n != 0) {
            count++;
            n &= n -1;
        }
        
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> out;
        
        for(int i = 0; i <= n; i++) {
            out.push_back(countBit(i));
        }
        
        return out;
    }
};