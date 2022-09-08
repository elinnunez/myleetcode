class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []
        
        nums.sort()
        
        for i in range(len(nums)-2):
            if i == 0 or i > 0 and nums[i] != nums[i-1]:
                low = i + 1
                high = len(nums)-1

                while low < high:
                    cursum = nums[i] + nums[low] + nums[high]

                    if cursum > 0:
                        high-=1
                    elif cursum < 0:
                        low+=1
                    else:
                        output.append([nums[i],nums[low],nums[high]])

                        while low < high and nums[low] == nums[low+1]:
                            low+=1

                        while high > low and nums[high] == nums[high-1]:
                            high-=1

                        low+=1
                        high-=1
            
        
        return output

# Time Complexity: O(n^2)
# Space Complexity: O(n)