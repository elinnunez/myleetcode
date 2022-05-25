class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        
        int cursum = 0;
        
        int count = 0;
        
        hash[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            
            cursum += nums[i];
            
            if(hash.count(cursum - k)) {
                count+= hash[cursum-k];
            }

            hash[cursum]++;
        }
        
        return count;
        
    }
};