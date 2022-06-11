class Solution:
    def majorityElement(self, nums: List[int]) -> int:
      map = {}
      majority = len(nums) // 2
      for element in nums:
        if element not in map:
          map[element] = 1
        else:
          map[element] += 1
         # If an element appears more than n/2 times, return that element
        if map[element] > majority:
          return element

      return None