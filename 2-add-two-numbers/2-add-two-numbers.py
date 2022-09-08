# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        
        remainder = 0
        
        while l1 or l2 or remainder != 0:
            x = 0
            y = 0
            
            if l1:
                x = l1.val
                l1 = l1.next
            
            if l2:
                y = l2.val
                l2 = l2.next
            
            cursum = x + y + remainder
            
            temp = ListNode(cursum % 10)
            
            remainder = cursum // 10
            
            cur.next = temp
            cur = cur.next
        
        return dummy.next

# Time Complexity: O(m+n+r) where r is # of loops while remainder != 0
# Space Complexity: O(m+r) where m is largest size between the two + extra remainder spots