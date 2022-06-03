class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int nxtNonKey = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[nxtNonKey] = nums[i];
                nxtNonKey++;
            }
        }
        
        return nxtNonKey;
        
    }
};