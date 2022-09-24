class Solution {
public:
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& out) {
        if(idx == nums.size()) {
            out.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx],nums[i]);
            backtrack(nums,idx+1,out);
            swap(nums[idx],nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        
        backtrack(nums,0,output);
        
        return output;
    }
};