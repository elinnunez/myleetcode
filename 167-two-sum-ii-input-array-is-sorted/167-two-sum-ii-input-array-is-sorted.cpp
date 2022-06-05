class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        vector<int> output;
        
        while (i < j) {
            int curSum = numbers[i]+numbers[j];
            if (curSum > target) {
                j--;
            } else if (curSum < target) {
                i++;
            } else {
                return {i+1,j+1};
            }
        }
        
        return output;
    }
};