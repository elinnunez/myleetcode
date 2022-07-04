class Solution {
public:
    void sortColors(vector<int>& nums) { // Bubble Sort: O(n^2)
        bool flag;
        int size = nums.size();
        
        for (int i = 0; i < size - 1; i++)
        {
            flag = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (flag == false)
            {
                break;
            }
        }
    };
};