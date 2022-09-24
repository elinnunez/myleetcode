class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& out, vector<int>& chosen, vector<int> cur) {
        if(cur.size() == nums.size()) {
            out.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(chosen[i] == 0) {
                cur.push_back(nums[i]);
                chosen[i] = 1;
                backtrack(nums,out,chosen,cur);
                chosen[i] = 0;
                cur.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> chosen(nums.size(),0);
        
        backtrack(nums,output,chosen,{});
        
        return output;
    }
};