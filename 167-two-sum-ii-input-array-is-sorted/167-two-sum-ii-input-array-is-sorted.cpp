class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        while (i < j && numbers[i]+numbers[j] != target) {
            int curSum = numbers[i]+numbers[j];
            if (curSum > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return {i+1,j+1};
    }
};