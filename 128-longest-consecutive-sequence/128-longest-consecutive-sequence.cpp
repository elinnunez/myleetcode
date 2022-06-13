class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> ht;
        
        for(int i = 0; i < nums.size(); i++) {
            ht[nums[i]] = NULL;
        }
        
        int curMax = INT_MIN;
        int prev = 0;
        int count = 0;
        
        for(auto const& it: ht) {
            if(it.first - prev > 1) {
                curMax = max(curMax,count);
                count = 0;
            }
            prev = it.first;
            count+=1;
        }
        
        return max(curMax,count);

    }
};