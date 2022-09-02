class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> count(nums.size()+1,0);
        
        vector<int> output;
        
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            
            if(count[nums[i]] > 1) {
                output.push_back(nums[i]);
            }
        }
        
        return output;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)