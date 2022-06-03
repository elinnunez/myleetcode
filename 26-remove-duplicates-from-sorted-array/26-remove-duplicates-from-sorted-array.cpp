class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nxtNonDupIdx = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[nxtNonDupIdx-1] != nums[i]) {
                nums[nxtNonDupIdx] = nums[i];
                nxtNonDupIdx++;
            }
        }
        
        return nxtNonDupIdx;
        
    }
};