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
        
        int curNum = nums[i];
        
        while(i < nums.size() && nums[i] == curNum) i++;
        
        backtrack(nums,output,i,cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        
        sort(nums.begin(),nums.end());
        
        backtrack(nums,output,0,{});
        
        return output;
    }
};
// Time Complexity: O(2^n*n)
// Space Complexity: O(2^n)