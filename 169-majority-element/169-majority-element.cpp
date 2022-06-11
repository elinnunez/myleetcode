class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<char,int> hash;
        
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            
            if(hash[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        
        return NULL;
    }
};