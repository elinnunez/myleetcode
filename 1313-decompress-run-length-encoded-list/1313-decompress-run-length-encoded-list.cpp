class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        vector<int> output;
        
        for(int i = 0; i < nums.size(); i+=2) {
            int freq = nums[i];
            int val = nums[i+1];
            vector<int> temp(freq,val);
            output.insert(output.end(), begin(temp), end(temp));
        }
        
        return output;
    }
};