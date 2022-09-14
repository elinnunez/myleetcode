class Solution:
    def findKth(self, nums1: List[int], L1, R1, nums2: List[int], L2, R2, k) -> int:
        if L1 > R1:
            return nums2[L2 + k - 1]
        
        if L2 > R2:
            return nums1[L1 + k - 1]
        
        mid1 = L1 + (R1-L1) // 2
        mid2 = L2 + (R2-L2) // 2
        
        if nums1[mid1] <= nums2[mid2]:
            if k <= (mid1-L1) + (mid2-L2) + 1:
                return self.findKth(nums1,L1,R1,nums2,L2,mid2-1,k)
            else:
                return self.findKth(nums1,mid1+1,R1,nums2,L2,R2,k-(mid1-L1)-1)
        else:
            if k <= (mid1-L1) + (mid2-L2)+1:
                return self.findKth(nums1,L1,mid1-1,nums2,L2,R2,k)
            else:
                return self.findKth(nums1,L1,R1,nums2,mid2+1,R2,k-(mid2-L2)-1)
            
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)
        k = (len1+len2+1)//2
        num1 = self.findKth(nums1,0,len1-1,nums2,0,len2-1,k)
        
        if (len1+len2) % 2 == 1:
            return num1
        
        num2 = self.findKth(nums1,0,len1-1,nums2,0,len2-1,k+1)
        
        return (num1+num2)/2.0