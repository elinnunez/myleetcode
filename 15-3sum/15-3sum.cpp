class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        
        if(nums.size() < 3) {
            return output;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++) {
            if(i == 0 || i > 0 && nums[i-1] != nums[i]) {
                int low = i+1;
                int high = nums.size()-1;
                
                while(low < high) {
                    int curSum = nums[i] + nums[low] + nums[high];
                    
                    if(curSum > 0) {
                        high--;
                    } else if (curSum < 0) {
                        low++;
                    } else {
                        output.push_back({nums[i], nums[low], nums[high]});
                        
                        while(low < high && nums[low] == nums[low+1]) {
                            low++;
                        }
                        while(high > low && nums[high-1] == nums[high]) {
                            high--;
                        }
                        high--;
                        low++;
                    }
                }
                
            }
        }
        
        return output;
        
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)