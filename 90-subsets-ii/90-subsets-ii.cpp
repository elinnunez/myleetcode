class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& output, set<vector<int>>& found, int i, vector<int> cur) {
        if(i >= nums.size()) {
            if(!found.count(cur)) {
                found.insert(cur);
                output.push_back(cur);
            }
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums,output,found,i+1,cur);
        cur.pop_back();
        
        int curNum = nums[i];
        
        while(i < nums.size() && nums[i] == curNum) i++;
        
        backtrack(nums,output,found,i,cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>> found;
        
        sort(nums.begin(),nums.end());
        
        backtrack(nums,output,found,0,{});
        
        return output;
    }
};
// Time Complexity: O(2^n*n)
// Space Complexity: O(2^n)