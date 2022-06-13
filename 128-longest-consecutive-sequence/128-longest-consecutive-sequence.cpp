class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> ht;
        
        for(int i = 0; i < nums.size(); i++) {
            ht[nums[i]] = 1;
        }
        
        int prev = 0;
        int maxCount = INT_MIN;
        int count = 0;
        
        for(auto const& it: ht) {
            if(it.first - prev > 1) {
                if(count > maxCount) {
                    maxCount = count;
                }
                count = 0;
            }
            prev = it.first;
            count+=1;
        }
        
        maxCount = max(maxCount,count);
        
        return maxCount;
    }
};