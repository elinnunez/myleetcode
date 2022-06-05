class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        
        if(nums.size() < 3) {
            return output;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++) {
            if(i==0 || i > 0 && nums[i] != nums[i-1]) {
                int low = i+1;
                int hi = nums.size() - 1;
                while(low < hi) {
                    
                    int curSum = nums[i] + nums[low] + nums[hi];
                    
                    if(curSum > 0) {
                        hi--;
                    } else if (curSum < 0) {
                        low++;
                    } else {
                        vector<int> temp = {nums[i],nums[low],nums[hi]};
                        
                        output.push_back(temp);
                        
                        while(low < hi && nums[low] == nums[low+1]){
                            low++;
                        }
                        // while(low < hi && nums[hi] == nums[hi-1]){
                        //     hi--;
                        // }
                        // hi--;
                        low++;
                    }
                }
            }
        }
        
        return output;
        
    }
};