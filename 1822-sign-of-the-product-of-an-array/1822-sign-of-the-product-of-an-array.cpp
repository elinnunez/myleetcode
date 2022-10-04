class Solution {
public:
    int signFunc(int p) {
        if (p == 0) return 0;
        if (p > 0) return 1;
        
        return -1;
    }
    
    int arraySign(vector<int>& nums) {
        long long product = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                return 0;
            }
            
            product *= signFunc(nums[i]);
        };
        
        return product;
    }
};