class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& output, vector<int> cur, set<vector<int>>& found, vector<int>& chosen) {
        if(cur.size() == nums.size() && !found.count(cur)) {
            found.insert(cur);
            output.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(chosen[i] != 1) {
                cur.push_back(nums[i]);
                chosen[i] = 1;
                backtrack(nums,output,cur,found,chosen);
                cur.pop_back();
                chosen[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>> found;
        vector<int> chosen(nums.size(),0);
        
        backtrack(nums,output,{},found,chosen);
        
        return output;
    }
};