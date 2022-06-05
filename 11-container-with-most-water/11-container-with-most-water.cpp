class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        
        int maxAmt = 0;
        
        while (i < j) {
            int curMaxAmt = min(height[i],height[j]) * (j-i);
            maxAmt = max(maxAmt,curMaxAmt);
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return maxAmt;
    }
};