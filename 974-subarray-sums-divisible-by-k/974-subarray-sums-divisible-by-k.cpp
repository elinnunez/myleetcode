class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        
        int cursum = 0;
        
        int count = 0;
        
        hash[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            cursum+= nums[i];
            int remainder = cursum % k;
            
            if(remainder < 0) {
                remainder+= k;
                //add k when remainder is negative
                //(-4)mod7= 3 but  C++ compiler gives -4
                //so to adjust that we will add the divisor, here 7 -> -4+7=3
            }
            
            if(hash.find(remainder) != hash.end()) {
                count+= hash[remainder];
            }
            hash[remainder]++;
        }
        
        return count;
    }
};