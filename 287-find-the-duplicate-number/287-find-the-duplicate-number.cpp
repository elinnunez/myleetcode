class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size()+1, 0);
        
        int duplicate = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            
            if(count[nums[i]] > 1) {
                duplicate = nums[i];
                break;
            }
        }
        
        return duplicate;
    }
};