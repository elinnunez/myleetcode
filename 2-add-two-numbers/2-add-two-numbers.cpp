/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        int remainder = 0;
        
        while(l1 != nullptr || l2 != nullptr || remainder != 0) {
            int x = 0;
            int y = 0;
            
            if(l1) {
                x = l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                y = l2->val;
                l2 = l2->next;
            }
            
            int sum = x + y + remainder;
            
            ListNode* temp = new ListNode(sum % 10);
            
            remainder = sum / 10;
            
            cur->next = temp;
            cur = cur->next;
        }
        
        return dummy->next;
        
    }
};