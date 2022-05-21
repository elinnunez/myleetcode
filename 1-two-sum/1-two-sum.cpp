class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        
        vector<int> temp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(ht.count(target-nums[i]) < 1) {
                ht[nums[i]] = i;
            } else {
                temp.push_back(ht[target-nums[i]]);
                temp.push_back(i);
            }
        }
        
        return temp;
        
    }
};