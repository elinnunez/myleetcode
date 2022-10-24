class Solution {
public:
    int binSearch(vector<int>& nums, int target, int i, int j) {
        if(i > j) return -1;
        
        int mid = i+(j-i)/2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[mid] > target) {
            return binSearch(nums,target,i,mid-1);
        } else {
            return binSearch(nums,target,mid+1,j);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return binSearch(nums,target,0,nums.size()-1);
    }
};