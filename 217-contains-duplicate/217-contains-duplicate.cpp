class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> values;
        
        for(int& num : nums) {
            if(values.count(num)) {
                return true;
            } else {
                values.insert(num);
            }
        }
        
        return false;
        
    }
};