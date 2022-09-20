class Solution {
public:
    void helper(vector<int>& candidates, int idx, int target, vector<vector<int>>& output, vector<int> temp) {
        if(target == 0) {
            output.push_back(temp);
            return;
        }
        
        if(target < 0) {
            return;
        }
        
        if(idx >= candidates.size()) {
            return;
        }
        
        temp.push_back(candidates[idx]);
        helper(candidates,idx,target-candidates[idx],output,temp);
        temp.pop_back();
        helper(candidates,idx+1,target,output,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        
        helper(candidates,0,target,output,{});
        
        return output;
    }
};