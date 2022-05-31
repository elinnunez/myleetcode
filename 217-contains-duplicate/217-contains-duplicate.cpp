class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Brute Force Solution
//         sort(nums.begin(), nums.end());
        
//         for(int i = 0; i < nums.size()-1; i++) {
//             if(nums[i] == nums[i+1]) {
//                 return true;
//             }
//         }
        
//         return false;
        
        map<int, int> bag;
        
        for(int i = 0; i < nums.size(); i++) {
            bag[nums[i]]++;
            if(bag[nums[i]] > 1) {
                return true;
            }
        }
        
        return false;
        
    }
};