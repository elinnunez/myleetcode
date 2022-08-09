class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        
        vector<int> temp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(!ht.count(target-nums[i])) {
                ht[nums[i]] = i;
            } else {
                temp = {ht[target-nums[i]], i};
                break;
            }
        }
        
        return temp;
        
    }
};