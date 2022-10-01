class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& output, int i, vector<int> cur) {
        if(i >= nums.size()) {
            output.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums,output,i+1,cur);
        cur.pop_back();
        backtrack(nums,output,i+1,cur);
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        
        backtrack(nums,output,0,{});
        
        return output;
    }
};